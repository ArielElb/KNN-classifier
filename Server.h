#ifndef ASS4_SERVER_H
#define ASS4_SERVER_H


class Server {
private:
    Menu menu;

public:
    void run();
    void checkUserInput();
    void getPort();
};


#endif //ASS4_SERVER_H
