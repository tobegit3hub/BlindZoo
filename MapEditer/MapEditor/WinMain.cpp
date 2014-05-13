//WinMain.cpp


#pragma comment (lib, "winmm.lib")		//for playing music

#include<Windows.h>
#include<MMSystem.h>

#include"resource.h"

#include"CMap.h"
#include"Algorithm.h"

ATOM MyRegisterClass(HINSTANCE hInstance);
bool InitInstance(HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void InitGraph();
void ReleaseGraph();
void PaintAll(HDC hDC);


LPCWSTR lpAppName = TEXT("MapEditer");
HINSTANCE hInst;
HWND hWnd;
HDC hDC;
static int cx, cy;

HDC hdcMemWall, hdcMemRoad, hdcMemAll;
HBITMAP hBmpWall, hBmpRoad, hBmpAll;

CMap Map;

int APIENTRY WinMain(HINSTANCE hInstance,
					 HINSTANCE hPrevInstance,
					 LPSTR lpCmdLine, 
					 int nCmdShow)
{

	MyRegisterClass(hInstance);

	InitInstance(hInstance, nCmdShow);

	MSG msg;
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}



ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASS wc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(1));
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WindowProc;
	wc.lpszClassName = lpAppName;
	wc.lpszMenuName  = MAKEINTRESOURCE(IDR_MENU1);
	wc.style = CS_HREDRAW | CS_VREDRAW;

	return RegisterClass(&wc);
}


bool InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hWnd = CreateWindow( lpAppName, lpAppName,
						 WS_OVERLAPPEDWINDOW,
						 CW_USEDEFAULT, CW_USEDEFAULT,
						 600, 600,
						 NULL,
						 NULL,
						 hInstance,
						 NULL);

	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);

	return true;
}



LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	PAINTSTRUCT ps;
	RECT rect;
	int MouseX, MouseY;


	switch(uMsg)
	{
	case WM_CREATE:
		{
			PlaySound(TEXT("avril - Black Star.wav"), NULL, SND_ASYNC | SND_FILENAME);

			hInst = (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE);
			GetClientRect(hWnd, &rect);

			srand( time(0) );
			//InitGraph();
		}break;

	case WM_SIZE:
		{
			cx = LOWORD(lParam);
			cy = HIWORD(lParam);
		}break;

	case WM_PAINT:
		{
			hDC = BeginPaint(hWnd, &ps);

			//for(int i=0;i<10;++i)
			//{
			//	for(int j=0;j<10;++j)
			//	{
			//		//Rectangle(hDC, i*cx/10, j*cy/10, (i+1)*cx/10, (j+1)*cy/10);

			//		if(WALL==Map.m_Map[i][j])
			//			Rectangle(hDC, i*cx/10, j*cy/10, (i+1)*cx/10, (j+1)*cy/10);
			//		if(ROAD==Map.m_Map[i][j])
			//			Ellipse(hDC, i*cx/10, j*cy/10, (i+1)*cx/10, (j+1)*cy/10);
			//		
			//	}
			//}
		
			//PaintAll(hDC);


			hBmpWall = (HBITMAP)LoadImage(NULL, TEXT(".//Wall.bmp"), IMAGE_BITMAP, cx/10, cy/10, LR_LOADFROMFILE);
			hdcMemWall = CreateCompatibleDC(hDC);
			SelectObject(hdcMemWall, hBmpWall);

			hBmpRoad = (HBITMAP)LoadImage(NULL, TEXT(".//Road.bmp"), IMAGE_BITMAP, cx/10, cy/10, LR_LOADFROMFILE);
			hdcMemRoad = CreateCompatibleDC(hDC);
			SelectObject(hdcMemRoad, hBmpRoad);

			for(int i=0;i<10;++i)
			{
				for(int j=0;j<10;++j)
				{
					if(WALL==Map.m_Map[i][j])
					{
						BitBlt(hDC, i*cx/10, j*cy/10, cx/10, cy/10, hdcMemWall, 0, 0, SRCAND);
					}
					else if(ROAD==Map.m_Map[i][j])
					{
						BitBlt(hDC, i*cx/10, j*cy/10, cx/10, cy/10, hdcMemRoad, 0, 0, SRCAND);
					}
				}
			}

			DeleteObject(hBmpWall);
			DeleteObject(hBmpRoad);

			ReleaseDC(hWnd, hdcMemWall);
			ReleaseDC(hWnd, hdcMemRoad);



			TextOut(hDC, cx/10, cx/10, TEXT("Entrance"), sizeof("Entrance")-1);
			TextOut(hDC, cx/10*8, cx/10*8, TEXT(" E x i  t "), sizeof(" E x i  t ")-1);

			EndPaint(hWnd, &ps);
		}break;


	case WM_LBUTTONDOWN:
		{
			MouseX = LOWORD(lParam);		
			MouseY = HIWORD(lParam);

			for(int i=0;i<10;++i)
			{
				for(int j=0;j<10;++j)
				{
					if(MouseX>i*cx/10 && MouseX<(i+1)*cx/10 && MouseY>j*cy/10 && MouseY<(j+1)*cy/10)
					{
	
						if(EMPTY==Map.m_Map[i][j])
							Map.m_Map[i][j] = WALL;
						else if(WALL==Map.m_Map[i][j])
							Map.m_Map[i][j] = ROAD;
						else if(ROAD==Map.m_Map[i][j])
							Map.m_Map[i][j] = WALL;

						rect.left = i*cx/10;
						rect.right = (i+1)*cx/10;
						rect.top = j*cy/10;
						rect.bottom = (j+1)*cy/10;
					
					}
				}
			}

			Map.Frame();

			Map.bModify = true;
			
			InvalidateRect(hWnd, &rect, true);		////////////////////////////////////////unable to redraw
			UpdateWindow(hWnd);

		}break;

	case WM_RBUTTONDOWN:
		{
			MouseX = LOWORD(lParam);		
			MouseY = HIWORD(lParam);

			for(int i=0;i<10;++i)
			{
				for(int j=0;j<10;++j)
				{
					if(MouseX>i*cx/10 && MouseX<(i+1)*cx/10 && MouseY>j*cy/10 && MouseY<(j+1)*cy/10)
					{
						Map.m_Map[i][j] = EMPTY;


						rect.left = i*cx/10;
						rect.right = (i+1)*cx/10;
						rect.top = j*cy/10;
						rect.bottom = (j+1)*cy/10;
					}
				}
			}


			Map.Frame();

			Map.bModify = true;

			InvalidateRect(hWnd, &rect, true);		////////////////////////////////////////unable to redraw
			UpdateWindow(hWnd);
		}break;


	case WM_COMMAND:
		{
			switch(wParam)
			{
			case IDM_OPEN:
				{
					OPENFILENAME ofn;						
					TCHAR szFile[MAX_PATH];
					ZeroMemory(&ofn,sizeof(ofn));
					ofn.lStructSize = sizeof(ofn);
					ofn.lpstrFile = szFile;
					ofn.lpstrFile[0] = TEXT('\0');
					ofn.nMaxFile = sizeof(szFile);
					ofn.lpstrFilter = TEXT("Text\0*.TXT\0ALL\0*.*\0C++\0*.cpp\0");
					ofn.nFilterIndex = 1;
					ofn.lpstrFileTitle = NULL;
					ofn.nMaxFileTitle = 0;						
					ofn.lpstrInitialDir = NULL;
					ofn.Flags = OFN_EXPLORER |OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
					GetOpenFileName(&ofn);

					TCHAR lpShortPath[256];
					GetShortPathName(szFile, lpShortPath, sizeof(lpShortPath));


					//TCHAR buffer[256+10];
					//wsprintf(buffer, "play %s", lpShortPath);
					////It's a problem to use UNICODE with TEXT()
					//SetDlgItemText(hDlg, IDE_TITLE, szFile);
					//mciSendString(buffer, NULL, 0, NULL);

					Map.Open(lpShortPath);

					GetClientRect(hWnd, &rect);
					InvalidateRect(hWnd, &rect, true);					


				}break;

			case IDM_SAVE:
				{
					if(!Map.IsFull())
					{
						int res = MessageBox(hWnd, TEXT("Hey, it's not full. Do you want me to fill with WALL?"), TEXT("No Full, No Save"), MB_YESNOCANCEL | MB_ICONWARNING);
						if(IDYES==res)
						{
							Map.Fill();

							GetClientRect(hWnd, &rect);
							InvalidateRect(hWnd, &rect, true);
						}
						else if(IDNO==res)
						{
							MessageBox(hWnd, TEXT("Then, you should fill to the full."), TEXT("No Full, No Save"), MB_OK | MB_ICONWARNING);
						}
					}			
					else 
					{
						if( !Map.IsConnect() && !Map.AlongSurface())
						{
							int res2 = MessageBox(hWnd, TEXT("It's not connected but do you want to forcefully save it?"), TEXT("No Connection, May No Save"), MB_YESNOCANCEL | MB_ICONWARNING);
							if(IDYES==res2)
							{
								Map.Save();
								MessageBox(hWnd, TEXT("OK, save the map successfully."), TEXT("Congratulations"), MB_OK | MB_ICONASTERISK);

								Map.bModify = false;
							}
						}				
						else
						{
							Map.Save();
							MessageBox(hWnd, TEXT("OK, save the map successfully."), TEXT("Congratulations"), MB_OK | MB_ICONASTERISK);

							Map.bModify = false;
						}
					}
				}break;

			case IDM_EXIT:
				{
					SendMessage(hWnd, WM_CLOSE, 0, 0);
				}break;

			case IDM_RESET:
				{
					int res = MessageBox(NULL, TEXT("Do you really want to discard it and reset the map?"), TEXT("Notice"), MB_YESNO | MB_ICONQUESTION);
					if(IDYES==res)
					{
						for(int i=0;i<10;++i)
							for(int j=0;j<10;++j)
								Map.m_Map[i][j] = EMPTY;
						Map.Frame();

						GetClientRect(hWnd, &rect);
						InvalidateRect(hWnd, &rect, true);
					}
				}break;

			case IDM_HOWTO:
				{
					MessageBox(NULL, TEXT("Just Click, Click and Click"), TEXT("No Tips"), MB_OK | MB_ICONEXCLAMATION);
				}break;


			case IDM_RIGHTDOWN:
				{
					int a[10][10];
					RightDown(a);

					Map.AlgorithmToMap(a);


					GetClientRect(hWnd, &rect);
					InvalidateRect(hWnd, &rect, true);
				}break;



			case IDM_UPDOWNRIGHTLEFT:
				{
					
					int a[10][10];
					UpDownRightLeft(a);
					
					Map.AlgorithmToMap(a);


					GetClientRect(hWnd, &rect);
					InvalidateRect(hWnd, &rect, true);
				}break;


			case IDM_UNIONFINDSET:
				{
					int a[10][10];
					UnionFindSet(a);

					Map.AlgorithmToMap(a);


					GetClientRect(hWnd, &rect);
					InvalidateRect(hWnd, &rect, true);
				}break;


			case IDM_TURNRIGHTPOSSIBLY:
				{
					if( Map.IsConnect() )
						MessageBox(hWnd, TEXT("It's definitely available."), TEXT("It's OK"), MB_OK | MB_ICONINFORMATION);
					else 
						MessageBox(hWnd, TEXT("It's not filled to the full or not even connected!!!"), TEXT("It's Not OK"), MB_OK | MB_ICONHAND);
				}break;

			case IDM_ALONGSURFACE:
				{
					if( Map.AlongSurface() )
						MessageBox(hWnd, TEXT("It's definitely available."), TEXT("It's OK"), MB_OK | MB_ICONINFORMATION);
					else 
						MessageBox(hWnd, TEXT("It's not filled to the full or not even connected!!!"), TEXT("It's Not OK"), MB_OK | MB_ICONHAND);					
				}break;
			}
		}break;


	case WM_CLOSE:
		{		
			//ReleaseGraph();

			if(Map.bModify)
			{
				int res = MessageBox(hWnd, TEXT("Do you want to exit without saving?"), TEXT("No Save, Recommand No Exit"), MB_YESNOCANCEL | MB_ICONWARNING);
				if(IDYES==res)
				{
					PostQuitMessage(0);
				}
				else if(IDNO==res)
				{
					MessageBox(hWnd, TEXT("Then, you should save the map."), TEXT("No Save, Recommand No Exit"), MB_OK | MB_ICONWARNING);
				}
			}	
			else
			{
				MessageBox(hWnd, TEXT("OK, the map has been save. Now have fun in BlindZoo."), TEXT("Congratulations"), MB_OK | MB_ICONASTERISK);
				PostQuitMessage(0);
			}
		}break;

	

	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	//return DefWindowProc(hWnd, uMsg, wParam, lParam);		//otherwise it will destroy the window anyway
}





void InitGraph()
{
	hDC = GetDC(hWnd);

	hBmpWall = (HBITMAP)LoadImage(NULL, TEXT(".//Wall.bmp"), IMAGE_BITMAP, cx/10, cy/10, LR_LOADFROMFILE);
	hdcMemWall = CreateCompatibleDC(hDC);
	SelectObject(hdcMemWall, hBmpWall);

	hBmpRoad = (HBITMAP)LoadImage(NULL, TEXT(".//Road.bmp"), IMAGE_BITMAP, cx/10, cy/10, LR_LOADFROMFILE);
	hdcMemRoad = CreateCompatibleDC(hDC);
	SelectObject(hdcMemRoad, hBmpRoad);

	
	ReleaseDC(hWnd, hDC);
}


void ReleaseGraph()
{
	DeleteObject(hBmpWall);
	DeleteObject(hBmpRoad);

	ReleaseDC(hWnd, hdcMemWall);
	ReleaseDC(hWnd, hdcMemRoad);
}


void PaintAll(HDC hDC)
{

	for(int i=0;i<10;++i)
	{
		for(int j=0;j<10;++j)
		{
			if(WALL==Map.m_Map[i][j])
			{
				BitBlt(hDC, i*cx/10, j*cy/10, cx/10, cy/10, hdcMemWall, 0, 0, SRCAND);
			}
			else if(ROAD==Map.m_Map[i][j])
			{
				BitBlt(hDC, i*cx/10, j*cy/10, cx/10, cy/10, hdcMemRoad, 0, 0, SRCAND);
			}
		}
	}

}
