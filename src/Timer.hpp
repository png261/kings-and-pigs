#pragma once

#include "SDL.hpp"

class Timer final
{
public:
    Timer();
    void start();
    void stop();
    void pause();
    void resume();
    void restart();
    Uint32 delta() const;
    Uint32 currentTime() const;
    bool isRunning() const;
    bool isPaused() const;

protected:
    Uint32 m_startMark;
    Uint32 m_stopMark;
    Uint32 m_pausedMark;
    bool m_bRunning;
    bool m_bPaused;
};

