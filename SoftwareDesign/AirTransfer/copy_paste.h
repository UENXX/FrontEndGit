#ifndef COPY_PASTE_H
#define COPY_PASTE_H

#include <cstdio>
#include <cassert>
#include <windows.h>
#include <cstring>
#include <vector>
class copy
{
    public:
        int input_length;
        int get_user_input();
        char *user_input;
        wchar_t *char2wchar(const char* cchar);
        copy();
        ~copy();
};
copy::copy()
{
    input_length = 0;
    user_input = NULL;
}
copy::~copy()
{
    input_length = 0;
    free(user_input);
    user_input = NULL;
}
copy::get_user_input(void)
{
    char *pData;
    size_t length;
    OpenClipboard(NULL);
    HANDLE hData=GetClipboardData(CF_TEXT);
    if(hData==NULL)
    {
        GlobalUnlock(hData);
        HDROP hDrop = HDROP(GetClipboardData(CF_HDROP)); // 获取剪切板中复制的文件列表相关句柄
        if (hDrop != NULL)
        {
            user_input = (char*)malloc(MAX_PATH+1);
            memset(user_input, MAX_PATH+1 ,0);
            UINT nNumOfFiles = DragQueryFile(hDrop, 0xFFFFFFFF, NULL, 0); // 得到文件个数
            if(nNumOfFiles!=1)
            {
                return -10;                      //代表复制了文件夹
            }
            DragQueryFile(hDrop, 0, char2wchar(user_input), MAX_PATH);  // 得到文件名
            user_input[strlen(user_input)] = 0;
            GlobalUnlock(hDrop);
            CloseClipboard();
            return -3;                               //代表复制的是文件
        }
    }
    length=GlobalSize(hData);
    user_input = (char*)malloc(length+1);
    memset(user_input,length+1,'\0');
    pData=(char*)GlobalLock(hData);
    strncpy(user_input,pData,length);
    GlobalUnlock(hData);
    CloseClipboard();
    user_input[length]=0;
    if(length==0)
        return -2;
    FILE *fp = fopen("user_input.txt","w");
    if(fp==NULL)
        return -1;
    fwrite(user_input,length,1,fp);
    fclose(fp);
    return 0;
}
wchar_t *copy::char2wchar(const char* cchar)
{
    wchar_t *m_wchar;
    int len = MultiByteToWideChar( CP_ACP ,0,cchar ,strlen( cchar), NULL,0);
    m_wchar= new wchar_t[len+1];
    MultiByteToWideChar( CP_ACP ,0,cchar,strlen( cchar),m_wchar,len);
    m_wchar[len]= '\0' ;
    return m_wchar;
}

class paste
{
    public:
        int set_user_input(char* input);
};
int paste::set_user_input(char* input)
{
    OpenClipboard(NULL);
    HGLOBAL hmem = GlobalAlloc(GHND, strlen(input) + 1);
    char *pmem = (char *)GlobalLock(hmem);
    EmptyClipboard();
    memcpy(pmem, input, strlen(input) + 1);
    SetClipboardData(CF_TEXT, hmem);
    CloseClipboard();
    GlobalFree(hmem);
    return 0;
}



#endif // COPY_PASTE_H
