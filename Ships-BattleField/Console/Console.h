#ifndef CONSOLE_H
#define CONSOLE_H

    #include <Windows.h>
    #include <string>

    class Console
    {
        private:
            HWND consoleWindow; //Window handle
            HANDLE screenHandle;
            HANDLE mouseInput;
            std::wstring title;

        public:
            Console();
            ~Console();

            HWND& getConsoleWindow() { return this->consoleWindow; }
            HANDLE& getScreenHandle() { return this->screenHandle; }            
            HANDLE& getInputHandle() { return this->mouseInput; }
            std::wstring& getTitle() { return this->title; }

            void disableQuickMode();

            void setConsoleSize(int height = 63, int width = 240);
            void setTitle(const std::wstring& title);
            void setFontColor(short textColor);

            void clear();
            void sleep(int milliseconds);

            static void staticClear();
            static void staticSleep(int milliseconds);
            static void staticSetFontColor(const HANDLE& screenHandle, short textColor);


            bool isHovered();

            bool isOpen();
    };
#endif