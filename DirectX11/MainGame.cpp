#include "framework.h"
#include "MainGame.h"

MainGame::~MainGame()
{
}

void MainGame::Init()
{
    //MemDc 메모리상의 dc를 하나 더 추가
    HBITMAP	 m_hOldBitmap, m_hBitmap;
    HDC	hdc = GetDC(g_hwnd); //기존 핸들
    g_MemDC = CreateCompatibleDC(hdc);
    m_hBitmap = CreateCompatibleBitmap(hdc, 800, 600);
    m_hOldBitmap = (HBITMAP)SelectObject(g_MemDC, m_hBitmap);
    ReleaseDC(g_hwnd, hdc);

    cc.position.x = 400.0f;
    cc.position.y = 300.0f;
    cc.scale = Vector2(500.0f, 500.0f);
    cc.rotation = 0.0f;

    hour.position.x = 400.0f;
    hour.position.y = 300.0f;
    hour.scale = Vector2(120.0f, 0.0f);
    hour.rotation = 0.0f;

    min.position.x = 400.0f;
    min.position.y = 300.0f;
    min.scale = Vector2(180.0f, 0.0f);
    min.rotation = 0.0f;

    sec.position.x = 400.0f;
    sec.position.y = 300.0f;
    sec.scale = Vector2(230.0f, 0.0f);
    sec.rotation = 0.0f;
}

void MainGame::Update()
{
    GetLocalTime(&localTime);

    hour.rotation = -DIV2PI + (float)localTime.wHour * 30.0f * ToRadian
        + (float)localTime.wMinute * 0.5f * ToRadian;
    min.rotation = -DIV2PI + (float)localTime.wMinute * 6.0f * ToRadian
        + (float)localTime.wSecond * 0.1f * ToRadian;
    sec.rotation = -DIV2PI + (float)localTime.wSecond * 6.0f * ToRadian
        + (float)localTime.wMilliseconds * 0.006f * ToRadian;

    cc.Update();
    hour.Update();
    min.Update();
    sec.Update();

    //키가 눌렸을 때 wm_paint 를 발생 시켜라
    InvalidateRect(g_hwnd, NULL, false);
}

void MainGame::Render()
{
    PAINTSTRUCT ps;
    //hdc-> 도화지
    g_hdc = BeginPaint(g_hwnd, &ps);

    //바탕색 깔기
    PatBlt(g_MemDC, 0, 0, 800, 600, WHITENESS);
    string FPS = "FPS : " + to_string(TIMER->GetFPS());
    TextOutA(g_MemDC, 0, 0, FPS.c_str(), FPS.size());

    string Time = to_string(localTime.wHour) + "시"
        + to_string(localTime.wMinute) + "분"
        + to_string(localTime.wSecond) + "초";
    TextOutA(g_MemDC, 0, 50, Time.c_str(), Time.size());

    cc.Render();
    hour.Render();
    min.Render();
    sec.Render();

    //고속 복사 g_MemDC에서 g_hdc로
    BitBlt(g_hdc, 0, 0, 800, 600, g_MemDC, 0, 0, SRCCOPY);

    EndPaint(g_hwnd, &ps);
}