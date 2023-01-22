#ifndef ASS4_CLIENTCLI_H
#define ASS4_CLIENTCLI_H

#include "General/Command.h"
#include "ClientCLI/AlgorithmSettings.h"
#include "ClientCLI/UploadFile.h"
#include "ClientCLI/DisplayClassiffications.h"
#include "ClientCLI/DownloadFile.h"
#include "ClientCLI/ClassificationKnn.h"
#include "IO/FileIO.h"
#include <vector>
#include <thread>

class ClientCLI {
private:
    DefaultIO* dio = nullptr;
    std::vector<Command *> commands;
    // vector <lineNumber, classification>
    void initCommands();
//    std::vector<std::pair<int,std::string>>;
public:
    explicit ClientCLI(DefaultIO *dio);
    virtual ~ClientCLI() = default;
    std::string path;

    void start();
};


#endif //ASS4_CLIENTCLI_H
