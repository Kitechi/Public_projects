#ifndef STRUCTDEF_H
#define STRUCTDEF_H

#define GHz(x) x*1000000000

#include <QString>

enum measType
{
    er      = 0,
    ei      = 1,
    ur      = 2,
    ui      = 3,
    s11Mag  = 4,
    s21Mag  = 5,
    noOfMeas= 6,
};

struct structSetting
{
    int scanHeight;
    int scanWidth;
    float scanInterval;
    int ScanPoints;
    int xLength;
    int yLength;
    bool scanstart;

    float PnaStartFreq;
    float PnaStopFreq;
    int   PnaSweepPoints;
    double PnaFreqStepSize;
    float PnaPower;
    float PnaIFBW;
    float PnametalPlateThickness;
    float PnadistToSample;
    float PnasampleThickness;
    int selectedMeas;
};

struct structResult
{
    bool filtPass1en;
    short filterType;
    short filterRadius;
    short filterItr;
    bool filtPass2en;
    short filterType2;
    short filterRadius2;
    short filterItr2;
    int vtwamStartFr;
    int vtwamEndFr;
};

struct structComplex
{
    float *real=nullptr;
    float *imag=nullptr;
    float *mag=nullptr;
};

struct structMeas
{
    float *f;
    structComplex e;
    structComplex u;
    structComplex s11;
    structComplex s21;
};

bool inline allocateMemToComplexStruct(structComplex* pComplex, int numPts)
{
    pComplex->real = new float[numPts];
    pComplex->imag = new float[numPts];
    pComplex->mag = new float[numPts];

    return true;
}

bool inline clearMemOfComplexStruct(structComplex* pComplex)
{
    delete pComplex->real;
    delete pComplex->imag;
    delete pComplex->mag;

    pComplex->real = nullptr;
    pComplex->imag = nullptr;
    pComplex->mag  = nullptr;

    return true;
}

bool inline clearMemOfMeasStruct(structMeas* pMeas)
{
    clearMemOfComplexStruct(&pMeas->e);
    clearMemOfComplexStruct(&pMeas->u);
    clearMemOfComplexStruct(&pMeas->s11);
    clearMemOfComplexStruct(&pMeas->s21);

    delete pMeas->f;
    pMeas->f = nullptr;

    delete pMeas;
    pMeas = nullptr;

    return true;
}

bool inline allocMemToMeasStruct(structMeas** pMeasArg, int numPts)
{
    structMeas* pMeasLoc;

    if (*pMeasArg != nullptr)
        clearMemOfMeasStruct(*pMeasArg);

    pMeasLoc = (structMeas*) new structMeas;
    pMeasLoc->f = new float[numPts];

    allocateMemToComplexStruct(&pMeasLoc->e,numPts);
    allocateMemToComplexStruct(&pMeasLoc->u,numPts);
    allocateMemToComplexStruct(&pMeasLoc->s11,numPts);
    allocateMemToComplexStruct(&pMeasLoc->s21,numPts);

    *pMeasArg = pMeasLoc;

    return true;
}
QString inline measName(int measIndex)
{
    QString retVal;
    const char * measName[] = {"Permittivity (real)","Permittivity (imag)","Permeability (real)","Permeability (imag)","S11","S21"};
    retVal =  measName[measIndex];
    return retVal;
}

#endif // STRUCTDEF_H
