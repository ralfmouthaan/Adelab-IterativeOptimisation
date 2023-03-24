#pragma once

class clsMeadowlark {

protected:

    // Used for creating SDK
    int Board_Number = 1;
    unsigned int Bit_Depth = 12U;
    bool Is_Nematic_Type = true;
    bool Use_GPU = false;
    int Max_Transients = 10U;
    int RAM_Write_Enable = 1;

    // Used for displaying holograms
    bool Wait_For_Trigger = false; // This feature is user - settable; use 1 for 'on' or 0 for 'off'
    int Timeout_ms = 5000;
    bool OutputPulseImageFlip = 0;
    bool OutputPulseImageRefresh = 0; // only supported on 1920x1152, FW rev 1.8.
    char* Regional_LUT;

    // Hadamard hologram-related
    char* HadamardMatrix;
    int HadamardMatrixSize;
    void GenerateHadamardMatrix(int n);

public:

    int Width = 0;
    int Height = 0;
    double WFC_Weights[18] = {};

    clsMeadowlark();
    ~clsMeadowlark();

    void LoadLUT(const char* LUT);
    void LoadWFC();

    void ShowHologramOnScreen(unsigned char* Holo);
    void ShowHologramOnSLM(unsigned char* Holo);

    unsigned char* ApplyPadding(unsigned char* OriginalHolo, int OriginalHeight, int OriginalWidth);
    unsigned char* ApplyZernikes(unsigned char* Holo, double ZernikeWeights[19]);

    unsigned char* GenerateBinaryGrating(int Gray1, int Gray2, int PixelsPerStripe);
    unsigned char* GenerateBlankHolo();
    unsigned char* GenerateBlazedGrating(double WeightingX, double WeightingY);
    unsigned char* GenerateCheckerboard(int Period);
    unsigned char* GenerateMacropixels(unsigned char* Array, int ArrayLength, int MacropixelWidth);
    unsigned char* GenerateHadamardMatrix(int ArrayLength, int HadamardIndex, int MacropixelWidth);

};
