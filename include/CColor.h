#pragma once

/**
 * @file CColor.h
 * @brief Contains the declaration of the CColor class.
 */

#include <array>
#include <vector>
#include <string>

#ifdef CALI_SUPPORT_IMGUI_COLORS
#include <imgui.h>
#endif

namespace Cali
{
    /**
     * @typedef RGBA
     * @brief RGBA color data.
     */
    typedef std::array<unsigned char, 4> RGBA;

    /**
     * @typedef RGB
     * @brief RGB color data.
     */
    typedef std::array<unsigned char, 3> RGB;

    /**
     * @typedef HEX_STRING
     * @brief HEX color data as a string with format #RRGGBB.
     */
    typedef std::string HEX_STRING; // EXAMPLE: #FF0000

    /**
     * @typedef HEX_STRING
     * @brief HEX color data as an integer with format 0xRRGGBB.
     */
    typedef int HEX_NUMBER; // EXAMPLE: 0xFF0000

    /**
     * @typedef RATIO
     * @brief RATIO color data.
     * @see https://en.wikipedia.org/wiki/Ratio_(mathematics)
     */
    typedef double RATIO; // EXAMPLE: 0.5

    /**
     * @brief Represents a color key also known as a chroma key.
     * @see https://en.wikipedia.org/wiki/Chroma_key
     */
    class CColorKey
    {
    private:
        /**
         * @brief RGBA color data.
         * @see https://en.wikipedia.org/wiki/RGBA_color_model
         */
        RGBA m_ColorRGBA = {0, 0, 0, 0};

        /**
         * @brief RGB color data.
         * @see https://en.wikipedia.org/wiki/RGB_color_model
         */
        RGB m_ColorRGB = {0, 0, 0};

        /**
         * @brief HEX color data as a string with format #RRGGBB.
         * @see https://en.wikipedia.org/wiki/HEX_color
         * */
        HEX_STRING m_ColorHEX = "";

        /**
         * @brief HEX color data as an integer with format 0xRRGGBB.
         * @see https://en.wikipedia.org/wiki/HEX_color
         * */
        HEX_NUMBER m_ColorHEXNumber = 0;

    public:
        /**
         * @brief Default constructor.
         * */
        CColorKey()
        {
            m_ColorRGBA = {0, 0, 0, 0};
            m_ColorRGB = {0, 0, 0};
            m_ColorHEX = "";
            m_ColorHEXNumber = 0;
        }

        /**
         * @brief Default deconstructor.
         * */
        ~CColorKey()
        {
            m_ColorRGBA = {0, 0, 0, 0};
            m_ColorRGB = {0, 0, 0};
            m_ColorHEX = "";
            m_ColorHEXNumber = 0;
        }

        /**
         * @brief Parameterized constructor.
         * @param colorRGBA RGBA color data.
         * @param colorRGB RGB color data.
         * @param colorHEX HEX color data as a string with format #RRGGBB.
         * @param colorHEXNumber HEX color data as an integer with format 0xRRGGBB.
         * */
        CColorKey(const RGBA &colorRGBA, const RGB &colorRGB, const HEX_STRING &colorHEX, const HEX_NUMBER &colorHEXNumber)
        {
            m_ColorRGBA = colorRGBA;
            m_ColorRGB = colorRGB;
            m_ColorHEX = colorHEX;
            m_ColorHEXNumber = colorHEXNumber;
        }

        /**
         * @brief Parameterized constructor.
         * @param colorRGBA RGBA color data.
         * */
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

        /**
         * @brief Parameterized constructor.
         * @param colorRGB RGB color data.
         * */
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

        /**
         * @brief Parameterized constructor.
         * @param colorHEX HEX color data as a string with format #RRGGBB.
         * */
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

        /**
         * @brief Parameterized constructor.
         * @param colorHEXNumber HEX color data as an integer with format 0xRRGGBB.
         * */
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

        /**
         * @brief Get the RGBA color data.
         * @return RGBA color data.
         * */
        RGBA GetColorRGBA() const
        {
            return m_ColorRGBA;
        }

        /**
         * @brief Get the RGB color data.
         * @return RGB color data.
         * */
        RGB GetColorRGB() const
        {
            return m_ColorRGB;
        }

        /**
         * @brief Get the HEX color data as a string with format #RRGGBB.
         * @return HEX color data.
         * */
        HEX_STRING GetColorHEX() const
        {
            return m_ColorHEX;
        }

        /**
         * @brief Get the HEX color data as an integer with format 0xRRGGBB.
         * @return HEX color data.
         * */
        HEX_NUMBER GetColorHEXNumber() const
        {
            return m_ColorHEXNumber;
        }

        /**
         * @brief Set the RGBA color data.
         * @param colorRGBA RGBA color data.
         * */
        void SetColorRGBA(const RGBA &colorRGBA)
        {
            m_ColorRGBA = colorRGBA;
        }

        /**
         * @brief Set the RGB color data.
         * @param colorRGB RGB color data.
         * */
        void SetColorRGB(const RGB &colorRGB)
        {
            m_ColorRGB = colorRGB;
        }

        /**
         * @brief Set the HEX color data.
         * @param colorHEX HEX color data as a string with format #RRGGBB.
         * */
        void SetColorHEX(const HEX_STRING &colorHEX)
        {
            m_ColorHEX = colorHEX;
        }

        /**
         * @brief Set the HEX color data.
         * @param colorHEXNumber HEX color data as an integer with format 0xRRGGBB.
         * */
        void SetColorHEXNumber(const HEX_NUMBER &colorHEXNumber)
        {
            m_ColorHEXNumber = colorHEXNumber;
        }
    };

    /**
     * @brief Color class.
     * */
    class CColor
    {
    private:
        std::string m_szName = "";
        std::vector<CColorKey> m_vecColorKeys = {};
        std::vector<RATIO> m_vecRatios = {};

    public:
        /**
         * @brief Default constructor.
         * */
        CColor()
        {
            m_szName = "";
            m_vecColorKeys.clear();
            m_vecRatios.clear();
        }

        /**
         * @brief Default deconstructor.
         * */
        ~CColor()
        {
            m_szName = "";
            m_vecColorKeys.clear();
            m_vecRatios.clear();
        }

        /**
         * @brief parameterized constructor for CColor class.
         * @param szName name of the color.
         * @param vecColorKeys color keys.
         * @param vecRatios ratios.
         * */
        CColor(const std::string &szName, const std::vector<CColorKey> &vecColorKeys, const std::vector<RATIO> &vecRatios)
        {
            m_szName = szName;
            m_vecColorKeys = vecColorKeys;
            m_vecRatios = vecRatios;
        }

        /**
         * @brief copy constructor for CColor class.
         * @param color color data.
         * */
        CColor(const CColor &color)
        {
            m_szName = color.m_szName;
            m_vecColorKeys = color.m_vecColorKeys;
            m_vecRatios = color.m_vecRatios;
        }

        /**
         * @brief assignment operator for CColor class.
         * @param color color data.
         * */
        CColor operator=(const CColor &color)
        {
            m_szName = color.m_szName;
            m_vecColorKeys = color.m_vecColorKeys;
            m_vecRatios = color.m_vecRatios;
            return *this;
        }

        /**
         * @brief equality operator for CColor class.
         * @param color color data.
         * */
        bool operator==(const CColor &color) const
        {
            return m_szName == color.m_szName && m_vecColorKeys == color.m_vecColorKeys && m_vecRatios == color.m_vecRatios;
        }

        /**
         * @brief inequality operator for CColor class.
         * @param color color data.
         * */
        bool operator!=(const CColor &color) const
        {
            return m_szName != color.m_szName || m_vecColorKeys != color.m_vecColorKeys || m_vecRatios != color.m_vecRatios;
        }

#ifdef CALI_SUPPORT_IMGUI_COLORS

        /**
         * @brief Get the ImGui color data. U can only use this function if SUPPORT_IMGUI_COLORS is defined.
         * @return ImGui color data (ImVec4).
         * */
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

        /**
         * @brief Get the name of the color.
         * @return The name of the color.
         * */
        const std::string &GetName() const
        {
            return m_szName;
        }

        /**
         * @brief Get the color keys.
         * @return The color keys.
         * */
        const std::vector<CColorKey> &GetColorKeys() const
        {
            return m_vecColorKeys;
        }

        /**
         * @brief Get the ratios.
         * @return The ratios.
         * */
        const std::vector<RATIO> &GetRatios() const
        {
            return m_vecRatios;
        }

        /**
         * @brief Set the name of the color.
         * @param szName The name of the color.
         * */
        void SetName(const std::string &szName)
        {
            m_szName = szName;
        }

        /**
         * @brief Set the color keys.
         * @param vecColorKeys The color keys.
         * */
        void SetColorKeys(const std::vector<CColorKey> &vecColorKeys)
        {
            m_vecColorKeys = vecColorKeys;
        }
    };
} // namespace Cali