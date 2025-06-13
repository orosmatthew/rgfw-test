#include <glad/glad.h>

#define RGFW_IMPLEMENTATION
#include <RGFW.h>

#include <stdio.h>

void keyfunc(
    RGFW_window* win,
    const RGFW_key key,
    [[maybe_unused]] u8 keyChar,
    [[maybe_unused]] RGFW_keymod keyMod,
    const RGFW_bool pressed)
{
    if (key == RGFW_escape && pressed) {
        RGFW_window_setShouldClose(win, 1);
    }
}

int main()
{
    RGFW_window* win
        = RGFW_createWindow("a window", RGFW_RECT(0, 0, 800, 600), RGFW_windowCenter | RGFW_windowNoResize);

    RGFW_window_makeCurrent(win);

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(RGFW_getProcAddress))) {
        fprintf(stderr, "Failed to initialized GLAD\n");
        return -1;
    }

    RGFW_setKeyCallback(keyfunc); // you can use callbacks like this if you want

    while (RGFW_window_shouldClose(win) == RGFW_FALSE) {
        while (RGFW_window_checkEvent(win)) {
            // or RGFW_window_checkEvents(); if you only want callbacks
            // you can either check the current event yourself
            if (win->event.type == RGFW_quit)
                break;

            if (win->event.type == RGFW_mouseButtonPressed && win->event.button == RGFW_mouseLeft) {
                printf("You clicked at x: %d, y: %d\n", win->event.point.x, win->event.point.y);
            }

            // or use the existing functions
            if (RGFW_isMousePressed(win, RGFW_mouseRight)) {
                printf("The right mouse button was clicked at x: %d, y: %d\n", win->event.point.x, win->event.point.y);
            }
        }

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // You can use modern OpenGL techniques, but this method is more straightforward for drawing just one triangle.
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.6f, -0.75f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.6f, -0.75f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.0f, 0.75f);
        glEnd();

        RGFW_window_swapBuffers(win);
    }

    RGFW_window_close(win);
    return 0;
}
