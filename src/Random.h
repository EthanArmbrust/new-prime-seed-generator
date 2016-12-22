class Random{
private:
  int inext;
  int inextp;
  const int MBIG = 0x7fffffff;
  const int MSEED = 0x9a4ec86;
  const int MZ = 0;
  int SeedArray[56];

public:
  Random();
  void setup(int);
  int Next(int);
  int Next(int, int);
  double GetSampleForLargeRange();
  int InternalSample();
  double Sample();
}
;
