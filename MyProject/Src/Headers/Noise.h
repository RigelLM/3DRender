#ifndef NOISE_H
#define NOISE_H
#include <cmath>

class Noise 
{
public:

    float persistence;
    int octave;

    Noise(float p, int o);

    double PerlinNoise(float x, float y);    // ���յ��ã�����(x,y)������Ӧ��PerlinNoiseֵ


private:

    double PrimeNoise(int x, int y);    // ����(x,y)��ȡһ����������ֵ

    double SmoothedNoise(int x, int y);   //�⻬����

    double Cosine_Interpolate(double a, double b, double x);  // ���Ҳ�ֵ

    double InterpolatedNoise(float x, float y);   // ��ȡ��ֵ����

};
#endif // NOISE_H
