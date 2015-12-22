#pragma once

#include <global.h>

#include <color.h>
#include <tonemap.h>

class Image {
public:
    explicit Image(const std::string &filename);
    ~Image() {}

    float *getData() { return (float *)m_pixels.get(); }

    const Color3f &ref(int i, int j) const;
    Color3f &ref(int i, int j);

    inline float getAverageLuminance() const { return m_averageLuminance; }
	inline float getAutoKeyValue() const { return m_autoKeyValue; }

    inline const Eigen::Vector2i &getSize() const { return m_size; }
    inline int getWidth() const { return m_size.x(); }
    inline int getHeight() const { return m_size.y(); }

    void saveAsPNG(const std::string &filename, TonemapOperator *tonemap, float exposure = 1.f) const;

private:
    std::unique_ptr<Color3f[]> m_pixels;

    Eigen::Vector2i m_size;

    float m_averageLuminance;
	float m_autoKeyValue;
};