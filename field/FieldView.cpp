#include "FieldView.h"

FieldView::FieldView(Field *other) {
    this->obj = other;
}

COORD makeCoord(int x, int y){
    COORD coord = {(SHORT)x, (SHORT)y};
    return coord;
}

void FieldView::showField() {
    auto sizes = obj->getFieldSize();

    HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hOUTPUT,&structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo( hOUTPUT, &structCursorInfo );
    CONSOLE_FONT_INFOEX cfi;

    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 15;
    cfi.dwFontSize.Y = 24;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;

    std::wcscpy(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(hOUTPUT, FALSE, &cfi);
    SetConsoleCursorPosition(hOUTPUT, makeCoord(0, 0));

    for(int row = 0; row < sizes.second; row++){
        for(int col = 0; col < sizes.first; col++){
            Cell cell = obj->getCell(row, col);
            CellView cellView(cell);
            SetConsoleTextAttribute(hOUTPUT, cellView.getColor());
            std::cout << " " << cellView.getView();
            SetConsoleTextAttribute(hOUTPUT,CellFeature::Default);
        }
        std::cout << "\n";
    }
}

void FieldView::showProperties(Player* player) {
    auto sizes = obj->getFieldSize();
    HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
    auto [health, coins, power] = player->getProperties();
    SetConsoleCursorPosition(hOUTPUT, makeCoord(sizes.first * 2, 0));
    std::cout << "Health: " << health << "\3";
    SetConsoleCursorPosition(hOUTPUT, makeCoord(sizes.first * 2,1));
    std::cout << "Coins: " << coins << "$";
    SetConsoleCursorPosition(hOUTPUT, makeCoord(sizes.first * 2,2));
    std::cout << "Power: "<< power << "%";
}

void FieldView::showGameOver() {
    std::cout<< "\n";
    std::cout<< "  ___   __   _  _ ____     __  _  _ ____ ____ \n"
                " / __) / _\\ ( \\/ |  __)   /  \\/ )( (  __|  _ \\\n"
                "( (_ \\/    \\/ \\/ \\) _)   (  O ) \\/ /) _) )   /\n"
                " \\___/\\_/\\_/\\_)(_(____)   \\__/ \\__/(____|__\\_)\n\n";
}

void FieldView::showGameWin() {
    std::cout<< "\n";
    std::cout<< " _  _ __  _  _    _  _ __ __ _     __   ___   __  __ __ _  _   \n"
                "( \\/ )  \\/ )( \\  / )( (  |  ( \\   / _\\ / __) / _\\(  |  ( \\/ \\  \n"
                " )  (  O ) \\/ (  \\ /\\ /)(/    /  /    ( (_ \\/    \\)(/    /\\_/  \n"
                "(__/ \\__/\\____/  (_/\\_|__)_)__)  \\_/\\_/\\___/\\_/\\_(__)_)__)(_)  \n\n";
}
