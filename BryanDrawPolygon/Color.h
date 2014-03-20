#pragma once
struct Color {
    Color(float _r, float _g, float _b, float _alpha) : r(_r), g(_g), b(_b), alpha(_alpha) {}
    Color() {}
	float r;
	float g;
	float b;
	float alpha;
};
