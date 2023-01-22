#ifndef ASS4_CLASSIFICATIONKNN_H
#define ASS4_CLASSIFICATIONKNN_H

#include "General/Command.h"
#include "IO/DefaultIO.h"

class ClassificationKnn : public Command {
    //void execute() override;
    void execute() override;
    virtual ~ClassificationKnn() = default;

public:
    explicit ClassificationKnn(DefaultIO *dio);
};
#endif //ASS4_CLASSIFICATIONKNN_H
