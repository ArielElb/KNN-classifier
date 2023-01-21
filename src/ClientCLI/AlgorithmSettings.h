#ifndef ASS4_ALGORITHMSETTINGS_H
#define ASS4_ALGORITHMSETTINGS_H

#include "General/Command.h"
#include "IO/DefaultIO.h"
#include <unistd.h>

class AlgorithmSettings : public Command {
    DefaultIO *dio;
public:
    void execute() override;
    virtual ~AlgorithmSettings() = default;
    AlgorithmSettings(DefaultIO *defaultIO);
};


#endif //ASS4_ALGORITHMSETTINGS_H
