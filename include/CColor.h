#pragma once

#include <array>
#include <vector>
#include <string>

#ifdef SUPPORT_IMGUI_COLORS
#include <imgui.h>
#endif

namespace Cali
{
    typedef std::array<unsigned char, 4> RGBA;
    typedef std::array<unsigned char, 3> RGB;

    typedef std::string HEX_STRING; // EXAMPLE: #FF0000
    typedef int HEX_NUMBER;         // EXAMPLE: 0xFF0000
    typedef double RATIO;           // EXAMPLE: 0.5

    class CColorKey
    {
    private:
        RGBA m_ColorRGBA = {0, 0, 0, 0};
        RGB m_ColorRGB = {0, 0, 0};
        HEX_STRING m_ColorHEX = "";
        HEX_NUMBER m_ColorHEXNumber = 0;

    public:
        CColorKey() {}

        ~CColorKey()
        {
            m_ColorRGBA = {0, 0, 0, 0};
            m_ColorRGB = {0, 0, 0};
            m_ColorHEX = "";
            m_ColorHEXNumber = 0;
        }

        CColorKey(const RGBA &colorRGBA, const RGB &colorRGB, const HEX_STRING &colorHEX, const HEX_NUMBER &colorHEXNumber)
        {
            m_ColorRGBA = colorRGBA;
            m_ColorRGB = colorRGB;
            m_ColorHEX = colorHEX;
            m_ColorHEXNumber = colorHEXNumber;
        }

        CColorKey(const RGBA &colorRGBA)
        {
            m_ColorRGBA = colorRGBA;

            m_ColorRGB = {
                static_cast<unsigned char>(colorRGBA[0]),
                static_cast<unsigned char>(colorRGBA[1]),
                static_cast<unsigned char>(colorRGBA[2])};

            m_ColorHEX = "#" + std::to_string(colorRGBA[0]) + std::to_string(colorRGBA[1]) + std::to_string(colorRGBA[2]);
            m_ColorHEXNumber = static_cast<HEX_NUMBER>(colorRGBA[0]) << 16 | static_cast<HEX_NUMBER>(colorRGBA[1]) << 8 | static_cast<HEX_NUMBER>(colorRGBA[2]);
        }

        CColorKey(const RGB &colorRGB)
        {
            m_ColorRGB = colorRGB;

            m_ColorRGBA = {
                static_cast<unsigned char>(colorRGB[0]),
                static_cast<unsigned char>(colorRGB[1]),
                static_cast<unsigned char>(colorRGB[2]),
                255};

            m_ColorHEX = "#" + std::to_string(colorRGB[0]) + std::to_string(colorRGB[1]) + std::to_string(colorRGB[2]);
            m_ColorHEXNumber = static_cast<HEX_NUMBER>(colorRGB[0]) << 16 | static_cast<HEX_NUMBER>(colorRGB[1]) << 8 | static_cast<HEX_NUMBER>(colorRGB[2]);
        }

        CColorKey(const HEX_STRING &colorHEX)
        {
            m_ColorHEX = colorHEX;

            m_ColorRGBA = {
                static_cast<unsigned char>(std::stoi(colorHEX.substr(1, 2), nullptr, 16)),
                static_cast<unsigned char>(std::stoi(colorHEX.substr(3, 2), nullptr, 16)),
                static_cast<unsigned char>(std::stoi(colorHEX.substr(5, 2), nullptr, 16)),
                static_cast<unsigned char>(std::stoi(colorHEX.substr(7, 2), nullptr, 16))};

            m_ColorRGB = {
                m_ColorRGBA[0],
                m_ColorRGBA[1],
                m_ColorRGBA[2]};

            m_ColorHEXNumber = static_cast<HEX_NUMBER>(m_ColorRGBA[0]) << 16 | static_cast<HEX_NUMBER>(m_ColorRGBA[1]) << 8 | static_cast<HEX_NUMBER>(m_ColorRGBA[2]);
        }

        CColorKey(const HEX_NUMBER &colorHEXNumber)
        {
            m_ColorHEXNumber = colorHEXNumber;

            m_ColorRGBA = {
                static_cast<unsigned char>(colorHEXNumber >> 16),
                static_cast<unsigned char>(colorHEXNumber >> 8),
                static_cast<unsigned char>(colorHEXNumber),
                static_cast<unsigned char>(colorHEXNumber >> 24)};

            m_ColorRGB = {
                m_ColorRGBA[0],
                m_ColorRGBA[1],
                m_ColorRGBA[2]};

            m_ColorHEX = "#" + std::to_string(m_ColorRGBA[0]) + std::to_string(m_ColorRGBA[1]) + std::to_string(m_ColorRGBA[2]);
        }

        RGBA GetColorRGBA() const
        {
            return m_ColorRGBA;
        }

        RGB GetColorRGB() const
        {
            return m_ColorRGB;
        }

        HEX_STRING GetColorHEX() const
        {
            return m_ColorHEX;
        }

        HEX_NUMBER GetColorHEXNumber() const
        {
            return m_ColorHEXNumber;
        }

        void SetColorRGBA(const RGBA &colorRGBA)
        {
            m_ColorRGBA = colorRGBA;
        }

        void SetColorRGB(const RGB &colorRGB)
        {
            m_ColorRGB = colorRGB;
        }

        void SetColorHEX(const HEX_STRING &colorHEX)
        {
            m_ColorHEX = colorHEX;
        }

        void SetColorHEXNumber(const HEX_NUMBER &colorHEXNumber)
        {
            m_ColorHEXNumber = colorHEXNumber;
        }
    };

    class CColor
    {
    private:
        std::string m_szName = "";
        std::vector<CColorKey> m_vecColorKeys = {};
        std::vector<RATIO> m_vecRatios = {};

    public:
        CColor()
        {
            m_szName = "";
            m_vecColorKeys.clear();
            m_vecRatios.clear();
        }

        ~CColor()
        {
            m_szName = "";
            m_vecColorKeys.clear();
            m_vecRatios.clear();
        }

        CColor operator=(const CColor &color)
        {
            m_szName = color.m_szName;
            m_vecColorKeys = color.m_vecColorKeys;
            m_vecRatios = color.m_vecRatios;
            return *this;
        }

        CColor(const std::string &szName, const std::vector<CColorKey> &vecColorKeys, const std::vector<RATIO> &vecRatios)
        {
            m_szName = szName;
            m_vecColorKeys = vecColorKeys;
            m_vecRatios = vecRatios;
        }

        CColor(const CColor &color)
        {
            m_szName = color.m_szName;
            m_vecColorKeys = color.m_vecColorKeys;
            m_vecRatios = color.m_vecRatios;
        }

        bool operator==(const CColor &color) const
        {
            return m_szName == color.m_szName && m_vecColorKeys == color.m_vecColorKeys && m_vecRatios == color.m_vecRatios;
        }

        bool operator!=(const CColor &color) const
        {
            return m_szName != color.m_szName || m_vecColorKeys != color.m_vecColorKeys || m_vecRatios != color.m_vecRatios;
        }

#ifdef SUPPORT_IMGUI_COLORS

        ImVec4 GetImGuiColor() const
        {
            ImVec4 color;
            color.x = m_vecColorKeys[0].GetColorRGBA()[0] / 255.0f;
            color.y = m_vecColorKeys[0].GetColorRGBA()[1] / 255.0f;
            color.z = m_vecColorKeys[0].GetColorRGBA()[2] / 255.0f;
            color.w = m_vecColorKeys[0].GetColorRGBA()[3] / 255.0f;

            return color;
        }

#endif

        const std::string &GetName() const
        {
            return m_szName;
        }

        const std::vector<CColorKey> &GetColorKeys() const
        {
            return m_vecColorKeys;
        }

        const std::vector<RATIO> &GetRatios() const
        {
            return m_vecRatios;
        }

        void SetName(const std::string &szName)
        {
            m_szName = szName;
        }

        void SetColorKeys(const std::vector<CColorKey> &vecColorKeys)
        {
            m_vecColorKeys = vecColorKeys;
        }
    };
} // namespace ImLeonardo