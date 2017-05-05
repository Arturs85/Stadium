#pragma once
using namespace Microsoft::Graphics::Canvas;


int distance(int x1, int y1, int x2, int y2);
double direction(int x1, int y1, int x2, int y2);
double disperse(double direction, double delta);
void angellipse(CanvasDrawingSession^ clds , int xc, int yc, int r, double a1, double a2, double ang, double ear);
int random(int max);
