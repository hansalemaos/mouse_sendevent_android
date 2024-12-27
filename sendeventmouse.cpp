#define _CRT_SECURE_NO_WARNINGS
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <getopt.h>
#include <linux/input.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/inotify.h>
#include <sys/ioctl.h>
// #include <sys/limits.h>
#include <algorithm>
#include <any>
#include <array>
#include <cctype>
#include <chrono>
#include <cmath>
#include <compare>
#include <cstring>
#include <deque>
#include <errno.h>
#include <fcntl.h>
#include <filesystem>
#include <fstream>
#include <functional>
#include <getopt.h>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <ranges>
#include <set>
#include <sstream>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <string_view>
#include <sys/ioctl.h>
#include <sys/poll.h>
#include <typeinfo>
#include <unistd.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <variant>
#include <vector>
namespace arghelpers
{
static constexpr int64_t MAX_64BIT_INT = 9223372036854775807;
static constexpr double MAX_64BIT_INT_AS_DOUBLE = 9223372036854775807.0;
static constexpr std::string_view nan_string = "NotANumber";
static constexpr std::string_view integer_numbers_string_view = "0123456789";
static constexpr std::string_view float_numbers_string_view = "0123456789.";
static constexpr std::string_view hex_upper_letters_string_view = "0123456789ABCDEF";
static constexpr std::string_view hex_lower_letters_string_view = "0123456789abcdef";
static constexpr std::string_view prefix_0b = "0b";
static constexpr std::string_view prefix_01 = "01";
static constexpr std::string_view prefix_0x = "0x";
static constexpr std::string_view number_0 = "0";
static constexpr char integer_numbers[] = "0123456789";
static constexpr char float_numbers[] = "0123456789.";
static constexpr char hex_upper_letters[] = "0123456789ABCDEF";
static constexpr unsigned int FNV_PRIME = 16777619u;
static constexpr std::string_view bool1 = "True";
static constexpr std::string_view bool2 = "False";
static constexpr std::string_view bool3 = "true";
static constexpr std::string_view bool4 = "false";
static constexpr std::string_view bool5 = "0";
static constexpr std::string_view bool6 = "1";
static constexpr std::string_view bool7 = "TRUE";
static constexpr std::string_view bool8 = "FALSE";
static constexpr std::string_view emptystringview = "";
static constexpr std::string_view zero1 = "0";
static constexpr std::string_view zero2 = "0.0";
static constexpr std::string_view zero3 = ".0";
static constexpr std::string_view zero4 = "-0";
static constexpr std::string_view zero5 = "-0.0";
static constexpr std::string_view zero6 = "+0.0";
constexpr std::array<uint8_t, 256> array_ascii_replace_non_alphanumeric = {
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  32,  32,  32,  32,  32,  32,  32,  65,
    66,  67,  68,  69,  70,  71,  72,  73,  74,  75,  76,  77,  78,  79,  80,  81,  82,  83,  84,  85,  86,  87,
    88,  89,  90,  32,  32,  32,  32,  32,  32,  97,  98,  99,  100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
    110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32};

constexpr std::array<uint8_t, 256> array_ascii_replace_non_printable = {
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,
    44,  45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61,  62,  63,  64,  65,
    66,  67,  68,  69,  70,  71,  72,  73,  74,  75,  76,  77,  78,  79,  80,  81,  82,  83,  84,  85,  86,  87,
    88,  89,  90,  91,  92,  93,  94,  95,  96,  97,  98,  99,  100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
    110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
    32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32};
constexpr std::array<uint8_t, 256> array_ascii_replace_non_numeric = {
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 0-15
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 16-31
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 32-47
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57,                         // 48-57 (digits '0'-'9')
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 58-73
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 74-89
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 90-105
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 106-121
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 122-137
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 138-153
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 154-169
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 170-185
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 186-201
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 202-217
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 218-233
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32  // 234-255
};
constexpr std::array<uint8_t, 256> array_ascii_replace_non_numeric_float = {
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 0-15
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 16-31
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 46, 32, // 32-47
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57,                         // 48-57 (digits '0'-'9')
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 58-73
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 74-89
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 90-105
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 106-121
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 122-137
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 138-153
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 154-169
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 170-185
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 186-201
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 202-217
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 218-233
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32  // 234-255
};

constexpr std::array<uint8_t, 256> array_ascii_replace_non_numeric_float_with_comma = {
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 0-15
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 16-31
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 44, 32, 46, 32, // 32-47
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57,                         // 48-57 (digits '0'-'9')
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 58-73
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 74-89
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 90-105
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 106-121
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 122-137
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 138-153
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 154-169
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 170-185
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 186-201
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 202-217
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, // 218-233
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32  // 234-255
};

static constexpr bool to_bool(const std::string_view s)
{

    if (s == bool1 || s == bool3 || s == bool6 || s == bool7)
    {
        return true;
    }
    return false;
}
static bool is_int_number(const std::string_view s)
{

    if (s.size() == 0)
    {
        return false;
    };
    if ((s.size() > 1) && ((s[0] == '-') || (s[0] == '+')) && ((s[1] != '-') && (s[1] != '+')))
    {
        return is_int_number(s.substr(1, s.size() - 1));
    }
    for (const char &i : s)
    {
        bool isnumber = false;
        for (const char &j : integer_numbers)
        {
            if (i == j)
            {
                isnumber = true;
                break;
            }
        }
        if (!isnumber)
        {
            return false;
        }
    }
    return true;
}
static bool is_float_number(const std::string_view s)
{
    if (s.size() == 0)
    {
        return false;
    };
    if ((s.size() > 1) && ((s[0] == '-') || (s[0] == '+')) && ((s[1] != '-') && (s[1] != '+')))
    {
        return is_float_number(s.substr(1, s.size() - 1));
    }
    size_t dotcounter = 0;
    for (const char &i : s)
    {
        bool isnumber = false;
        for (const char &j : float_numbers)
        {
            if (i == j)
            {
                if (i == '.')
                {
                    dotcounter += 1;
                    if (dotcounter > 1)
                    {
                        return false;
                    }
                }
                isnumber = true;
                break;
            }
        }
        if (!isnumber)
        {
            return false;
        }
    }
    return true;
}
static std::variant<double, int64_t> to_float_or_int(std::string_view s)
{
    std::variant<double, int64_t> returnvalue{};
    std::string tmpstring = std::string(s);
    if (is_int_number(s))
    {
        returnvalue = std::stoll(tmpstring);
    }
    else if (is_float_number(s))
    {
        returnvalue = std::stod(tmpstring);
    }
    return returnvalue;
}
bool check_if_string_is_valid_float_zero(const std::string_view str)
{

    if (is_float_number(str))
    {
        if (atof(str.data()) == 0)
        {
            return true;
        }
    }
    size_t strlen = str.size();
    if ((strlen > 1) && (str[0] == '+') && (is_float_number(str.substr(1, strlen - 1))))
    {
        return ((atof(&str.data()[1])) == 0);
    }
    if ((strlen > 1) && (str[0] == '-') && (is_float_number(str.substr(1, strlen - 1))))
    {
        return ((atof(&str.data()[1])) == 0);
    }
    return false;
}

bool check_if_string_is_valid_int_zero(const std::string_view str)
{

    if ((str == zero1) || (str == zero2) || (str == zero3) || (str == zero4) || (str == zero5) || (str == zero6))
    {
        return true;
    }

    size_t strlen = str.size();

    if (strlen == 0)
    {
        return false;
    }
    if ((strlen > 1) && (str[0] == '+') && (is_float_number(str.substr(1, strlen - 1))))
    {
        return (int(atof(&str.data()[1])) == 0);
    }
    if ((strlen > 1) && (str[0] == '-') && (is_float_number(str.substr(1, strlen - 1))))
    {
        return ((atof(&str.data()[1])) == 0);
    }
    if (is_int_number(str))
    {
        return (int(atof(str.data())) == 0);
    }

    if ((str[0] != '0') && (str[0] != '.'))
    {
        return false;
    }
    if ((str[0] == '.') && (strlen == 1))
    {
        return false;
    }

    if (str[0] == '.')
    {
        return is_int_number(str.substr(1, strlen - 1));
    }
    if ((str[0] == '0') && (strlen == 1))
    {
        return true;
    }
    if (is_float_number(str))
    {
        double tempdouble = atof(str.data());
        return (tempdouble < 1) && (tempdouble >= 0);
    }
    return false;
}
int64_t convert_to_int_at_any_cost(const std::string_view _sv, int64_t nan_value)
{
    std::variant<double, int64_t> tmpvalue = to_float_or_int(_sv);
    int64_t tmpnumber;
    try
    {
        tmpnumber = std::get<int64_t>(tmpvalue);
    }
    catch (...)
    {
        try
        {
            tmpnumber = (int64_t)(std::get<double>(tmpvalue));
        }
        catch (...)
        {
            // do nothing
        }
    }

    if (tmpnumber != 0)
    {
        return tmpnumber;
    }
    if ((tmpnumber == 0) && (check_if_string_is_valid_int_zero(_sv)))
    {
        return 0;
    }

    return nan_value;
}
double convert_to_double_at_any_cost(const std::string_view _sv, double nan_value)
{
    std::variant<double, int64_t> tmpvalue = to_float_or_int(_sv);
    double tmpnumber;
    try
    {
        tmpnumber = std::get<double>(tmpvalue);
    }
    catch (...)
    {
        try
        {
            tmpnumber = (double)(std::get<int64_t>(tmpvalue));
        }
        catch (...)
        {
            // do nothing
        }
    }
    if (tmpnumber != 0)
    {
        return tmpnumber;
    }
    if ((tmpnumber == 0) && (check_if_string_is_valid_float_zero(_sv)))
    {
        return 0;
    }

    return nan_value;
}
static constexpr bool is_hex_notation_upper_with_0x(const std::string_view input)
{
    return input.compare(0, 2, prefix_0x) == 0 && input.size() > 2 &&
           (input.find_first_not_of(hex_upper_letters_string_view, 2) == std::string_view::npos);
}
static constexpr bool is_hex_notation_upper_without_0x(const std::string_view input)
{
    return input.size() > 0 && (input.find_first_not_of(hex_upper_letters_string_view, 2) == std::string_view::npos);
}
static constexpr bool is_hex_notation_lower_with_0x(const std::string_view input)
{
    return input.compare(0, 2, prefix_0x) == 0 && input.size() > 2 &&
           (input.find_first_not_of(hex_lower_letters_string_view, 2) == std::string_view::npos);
}
static constexpr bool is_hex_notation_lower_without_0x(const std::string_view input)
{
    return input.size() > 0 && (input.find_first_not_of(hex_lower_letters_string_view, 2) == std::string_view::npos);
}
static std::string normalize_whitespaces(const std::string_view &invecj)
{
    std::string outvecj;
    outvecj.reserve(invecj.size());
    int last_whitespace_counter = 1;
    for (size_t i = 0; i < invecj.size(); i++)
    {
        if ((last_whitespace_counter == 0) && ((invecj[i] == ' ') || (invecj[i] == '\t') || (invecj[i] == '\n') ||
                                               (invecj[i] == '\r') || (invecj[i] == '\v') || (invecj[i] == '\f')))
        {
            outvecj += ' ';
            last_whitespace_counter += 1;
            continue;
        }
        else if ((last_whitespace_counter != 0) && ((invecj[i] == ' ') || (invecj[i] == '\t') || (invecj[i] == '\n') ||
                                                    (invecj[i] == '\r') || (invecj[i] == '\v') || (invecj[i] == '\f')))
        {
            last_whitespace_counter += 1;
            continue;
        }
        last_whitespace_counter = 0;
        outvecj += invecj[i];
    }
    if ((!outvecj.empty()) && (outvecj.back() == ' '))
    {
        outvecj.resize(outvecj.size() - 1);
    }

    return outvecj;
}
std::string remove_whitespaces(const std::string_view invecj)
{
    std::string outvecj;
    outvecj.reserve(invecj.size());
    for (size_t i = 0; i < invecj.size(); i++)
    {
        if ((invecj[i] == ' ') || (invecj[i] == '\t') || (invecj[i] == '\n') || (invecj[i] == '\r') ||
            (invecj[i] == '\v') || (invecj[i] == '\f'))
        {
            continue;
        }
        outvecj += invecj[i];
    }

    return outvecj;
}
std::string replace_fu(const std::string_view s, int op)
{
    std::string outv;
    outv.reserve(s.size());
    auto siterstart = s.begin();
    auto siterend = s.end();
    if (op == 0)
    {
        while (siterstart != siterend)
        {
            outv += (array_ascii_replace_non_alphanumeric[*siterstart++]);
        }
    }
    else if (op == 1)
    {
        while (siterstart != siterend)
        {
            outv += (array_ascii_replace_non_printable[*siterstart++]);
        }
    }
    else if (op == 2)
    {
        while (siterstart != siterend)
        {
            outv += (array_ascii_replace_non_numeric[*siterstart++]);
        }
    }
    else if (op == 3)
    {
        while (siterstart != siterend)
        {
            outv += (array_ascii_replace_non_numeric_float[*siterstart++]);
        }
    }
    else if (op == 4)
    {
        while (siterstart != siterend)
        {
            outv += (array_ascii_replace_non_numeric_float_with_comma[*siterstart++]);
        }
    }
    return outv;
}

std::string replace_non_alphanumeric_with_spaces(std::string_view _sv)
{
    return replace_fu(_sv, 0);
}
std::string replace_non_printable_with_spaces(std::string_view _sv)
{
    return replace_fu(_sv, 1);
}
std::string replace_non_decimal_with_spaces(std::string_view _sv)
{
    return replace_fu(_sv, 2);
}
std::string replace_non_float_with_spaces(std::string_view _sv)
{
    return replace_fu(_sv, 3);
}
std::string replace_non_float_with_spaces_and_comma(std::string_view _sv)
{
    return replace_fu(_sv, 4);
}
std::vector<std::pair<std::string, std::string>> parse_args_to_string_vector(int argc, char *argv[])
{
    std::vector<std::pair<std::string, std::string>> args;
    args.reserve(argc);
    for (size_t i{0}; i < argc; i++)
    {
        if (i == 0)
        {
            args.emplace_back(std::make_pair("__FILE__", std::string(argv[i])));
        }
        else
        {
            std::string tmpstring{argv[i]};
            size_t idxequal{tmpstring.find('=')};
            if (idxequal != std::string::npos && idxequal > 2)
            {
                args.emplace_back(std::make_pair(tmpstring.substr(2, idxequal - 2), tmpstring.substr(idxequal + 1)));
            }
            // args.push_back(std::make_pair(std::string(argv[i]), std::string(argv[i + 1])));
        }
    }
    return args;
}
static bool compare2strings(const std::string_view s1, const std::string_view s2)
{
    if (s1.size() != s2.size())
    {
        return false;
    }
    auto it1 = s1.begin();
    auto it2 = s2.begin();
    while (it1 != s1.end())
    {
        if (*it1 != *it2)
        {
            return false;
        }
        it1++;
        it2++;
    }
    return true;
}
static bool compare2strings(const char *s1, const std::string_view s2)
{
    const std::string_view s1view{s1};
    return compare2strings(s1view, s2);
}
static bool compare2strings(const char *s1, const char *s2)
{
    const std::string_view s1view{s1};
    const std::string_view s2view{s2};
    return compare2strings(s1view, s2view);
}
static bool compare2strings(const std::string_view s1, const char *s2)
{
    const std::string_view s2view{s2};
    return compare2strings(s1, s2view);
}

static std::vector<int64_t> parse_ints_to_vector(const std::string_view s, char delim = ',',
                                                 int64_t nan_value = MAX_64BIT_INT)
{
    std::vector<int64_t> result;
    result.reserve(s.size() / 4);
    auto strs = s | std::views::split(delim);
    for (const auto &ref : strs)
    {
        std::string_view sv{ref.begin(), ref.end()};
        result.emplace_back(convert_to_int_at_any_cost(sv, nan_value));
    }

    return result;
}
static std::vector<double> parse_doubles_to_vector(const std::string_view s, char delim = ',',
                                                   int64_t nan_value = MAX_64BIT_INT_AS_DOUBLE)
{
    std::vector<double> result;
    result.reserve(s.size() / 4);
    auto strs = s | std::views::split(delim);
    for (const auto &ref : strs)
    {
        std::string_view sv{ref.begin(), ref.end()};
        result.emplace_back(convert_to_double_at_any_cost(sv, nan_value));
    }
    return result;
}
static std::vector<std::pair<int64_t, int64_t>> parse_int_pairs_to_vector(const std::string_view s,
                                                                          int64_t nan_value = MAX_64BIT_INT)
{
    std::string s2{replace_non_float_with_spaces_and_comma(s)};
    std::string s3{normalize_whitespaces(s2)};
    std::vector<std::pair<int64_t, int64_t>> result;
    result.reserve(s.size() / 4);
    auto strs = s3 | std::views::split(' ');
    for (const auto &ref : strs)
    {
        std::string_view sv{ref.begin(), ref.end()};
        auto floatsnumbers = sv | std::views::split(',');
        size_t numbercounter = 0;
        int64_t firstvalueint = nan_value, secondvalueint = nan_value;
        for (const auto &ref2 : floatsnumbers)
        {
            std::string_view first_sv{ref2.begin(), ref2.end()};
            double firstvalue = convert_to_double_at_any_cost(first_sv, (double)nan_value);
            if (numbercounter == 0)
            {
                firstvalueint = (int64_t)firstvalue;
            }
            else if (numbercounter == 1)
            {
                secondvalueint = (int64_t)firstvalue;
            }
            numbercounter++;
        }
        result.emplace_back(std::make_pair(firstvalueint, secondvalueint));
    }
    return result;
}

static std::vector<std::pair<double, double>> parse_double_pairs_to_vector(const std::string_view s,
                                                                           double nan_value = MAX_64BIT_INT_AS_DOUBLE)
{
    std::string s2{replace_non_float_with_spaces_and_comma(s)};
    std::string s3{normalize_whitespaces(s2)};
    std::vector<std::pair<double, double>> result;
    result.reserve(s.size() / 4);
    auto strs = s3 | std::views::split(' ');
    for (const auto &ref : strs)
    {
        std::string_view sv{ref.begin(), ref.end()};
        auto floatsnumbers = sv | std::views::split(',');
        size_t numbercounter = 0;
        double firstvalueint = nan_value, secondvalueint = nan_value;
        for (const auto &ref2 : floatsnumbers)
        {
            std::string_view first_sv{ref2.begin(), ref2.end()};
            double firstvalue = convert_to_double_at_any_cost(first_sv, nan_value);
            if (numbercounter == 0)
            {
                firstvalueint = firstvalue;
            }
            else if (numbercounter == 1)
            {
                secondvalueint = firstvalue;
            }
            numbercounter++;
        }
        result.emplace_back(std::make_pair(firstvalueint, secondvalueint));
    }
    return result;
}
} // namespace arghelpers

static constexpr input_event sync_event{{0, 0}, 0, 0, 0};
static constexpr std::pair<input_event, int64_t> sync_event_no_sleep{{{0, 0}, 0, 0, 0}, 0};

void sleep_ms(int ms)
{
    usleep(ms * 1000);
}

void sleep_us(int us)
{
    usleep(us);
}
void sleep_seconds(int s)
{
    usleep(s * 1000000);
}

using tabsm = std::unordered_map<int, std::unordered_map<int, std::unordered_map<int, int>>>;
using tabsmsub = std::unordered_map<int, std::unordered_map<int, int>>;

tabsm absmap{};
tabsm position_now{};

std::unordered_map<int, std::string> device_mapping{};

typedef struct mouselike_devices
{
    std::string device_path;
    uint16_t is_mouse;
    uint16_t is_touch;
    uint16_t event_code;
    uint16_t event_value_1;
    uint16_t event_value_2;
    int32_t max_value_x;
    int32_t max_value_y;
    int32_t current_value_x;
    int32_t current_value_y;

} mlikedev;

std::ostream &operator<<(std::ostream &os, const mouselike_devices &thestring)
{
    os << "\n--------------------------------------------\n";
    os << "device_path: " << thestring.device_path << '\n';
    os << "is_mouse: " << thestring.is_mouse << '\n';
    os << "is_touch: " << thestring.is_touch << '\n';
    os << "event_code: " << thestring.event_code << '\n';
    os << "event_value_1: " << thestring.event_value_1 << '\n';
    os << "event_value_2: " << thestring.event_value_2 << '\n';
    os << "max_value_x: " << thestring.max_value_x << '\n';
    os << "max_value_y: " << thestring.max_value_y << '\n';
    os << "current_value_x: " << thestring.current_value_x << '\n';
    os << "current_value_y: " << thestring.current_value_y << '\n';

    return os;
}

struct label
{
    const char *name;
    int value;
};
#define LABEL(constant) {#constant, constant}
#define LABEL_END {NULL, -1}
static struct label input_prop_labels[] = {
    LABEL(INPUT_PROP_POINTER),
    LABEL(INPUT_PROP_DIRECT),
    LABEL(INPUT_PROP_BUTTONPAD),
    LABEL(INPUT_PROP_SEMI_MT),
    LABEL_END,
};
static struct label ev_labels[] = {
    LABEL(EV_SYN), LABEL(EV_KEY), LABEL(EV_REL), LABEL(EV_ABS), LABEL(EV_MSC),       LABEL(EV_SW), LABEL(EV_LED),
    LABEL(EV_SND), LABEL(EV_REP), LABEL(EV_FF),  LABEL(EV_PWR), LABEL(EV_FF_STATUS), LABEL_END,
};
static struct label syn_labels[] = {
    LABEL(SYN_REPORT), LABEL(SYN_CONFIG), LABEL(SYN_MT_REPORT), LABEL(SYN_DROPPED), LABEL_END,
};
static struct label key_labels[] = {
    LABEL(KEY_RESERVED),
    LABEL(KEY_ESC),
    LABEL(KEY_1),
    LABEL(KEY_2),
    LABEL(KEY_3),
    LABEL(KEY_4),
    LABEL(KEY_5),
    LABEL(KEY_6),
    LABEL(KEY_7),
    LABEL(KEY_8),
    LABEL(KEY_9),
    LABEL(KEY_0),
    LABEL(KEY_MINUS),
    LABEL(KEY_EQUAL),
    LABEL(KEY_BACKSPACE),
    LABEL(KEY_TAB),
    LABEL(KEY_Q),
    LABEL(KEY_W),
    LABEL(KEY_E),
    LABEL(KEY_R),
    LABEL(KEY_T),
    LABEL(KEY_Y),
    LABEL(KEY_U),
    LABEL(KEY_I),
    LABEL(KEY_O),
    LABEL(KEY_P),
    LABEL(KEY_LEFTBRACE),
    LABEL(KEY_RIGHTBRACE),
    LABEL(KEY_ENTER),
    LABEL(KEY_LEFTCTRL),
    LABEL(KEY_A),
    LABEL(KEY_S),
    LABEL(KEY_D),
    LABEL(KEY_F),
    LABEL(KEY_G),
    LABEL(KEY_H),
    LABEL(KEY_J),
    LABEL(KEY_K),
    LABEL(KEY_L),
    LABEL(KEY_SEMICOLON),
    LABEL(KEY_APOSTROPHE),
    LABEL(KEY_GRAVE),
    LABEL(KEY_LEFTSHIFT),
    LABEL(KEY_BACKSLASH),
    LABEL(KEY_Z),
    LABEL(KEY_X),
    LABEL(KEY_C),
    LABEL(KEY_V),
    LABEL(KEY_B),
    LABEL(KEY_N),
    LABEL(KEY_M),
    LABEL(KEY_COMMA),
    LABEL(KEY_DOT),
    LABEL(KEY_SLASH),
    LABEL(KEY_RIGHTSHIFT),
    LABEL(KEY_KPASTERISK),
    LABEL(KEY_LEFTALT),
    LABEL(KEY_SPACE),
    LABEL(KEY_CAPSLOCK),
    LABEL(KEY_F1),
    LABEL(KEY_F2),
    LABEL(KEY_F3),
    LABEL(KEY_F4),
    LABEL(KEY_F5),
    LABEL(KEY_F6),
    LABEL(KEY_F7),
    LABEL(KEY_F8),
    LABEL(KEY_F9),
    LABEL(KEY_F10),
    LABEL(KEY_NUMLOCK),
    LABEL(KEY_SCROLLLOCK),
    LABEL(KEY_KP7),
    LABEL(KEY_KP8),
    LABEL(KEY_KP9),
    LABEL(KEY_KPMINUS),
    LABEL(KEY_KP4),
    LABEL(KEY_KP5),
    LABEL(KEY_KP6),
    LABEL(KEY_KPPLUS),
    LABEL(KEY_KP1),
    LABEL(KEY_KP2),
    LABEL(KEY_KP3),
    LABEL(KEY_KP0),
    LABEL(KEY_KPDOT),
    LABEL(KEY_ZENKAKUHANKAKU),
    LABEL(KEY_102ND),
    LABEL(KEY_F11),
    LABEL(KEY_F12),
    LABEL(KEY_RO),
    LABEL(KEY_KATAKANA),
    LABEL(KEY_HIRAGANA),
    LABEL(KEY_HENKAN),
    LABEL(KEY_KATAKANAHIRAGANA),
    LABEL(KEY_MUHENKAN),
    LABEL(KEY_KPJPCOMMA),
    LABEL(KEY_KPENTER),
    LABEL(KEY_RIGHTCTRL),
    LABEL(KEY_KPSLASH),
    LABEL(KEY_SYSRQ),
    LABEL(KEY_RIGHTALT),
    LABEL(KEY_LINEFEED),
    LABEL(KEY_HOME),
    LABEL(KEY_UP),
    LABEL(KEY_PAGEUP),
    LABEL(KEY_LEFT),
    LABEL(KEY_RIGHT),
    LABEL(KEY_END),
    LABEL(KEY_DOWN),
    LABEL(KEY_PAGEDOWN),
    LABEL(KEY_INSERT),
    LABEL(KEY_DELETE),
    LABEL(KEY_MACRO),
    LABEL(KEY_MUTE),
    LABEL(KEY_VOLUMEDOWN),
    LABEL(KEY_VOLUMEUP),
    LABEL(KEY_POWER),
    LABEL(KEY_KPEQUAL),
    LABEL(KEY_KPPLUSMINUS),
    LABEL(KEY_PAUSE),
    LABEL(KEY_SCALE),
    LABEL(KEY_KPCOMMA),
    LABEL(KEY_HANGEUL),
    LABEL(KEY_HANGUEL),
    LABEL(KEY_HANJA),
    LABEL(KEY_YEN),
    LABEL(KEY_LEFTMETA),
    LABEL(KEY_RIGHTMETA),
    LABEL(KEY_COMPOSE),
    LABEL(KEY_STOP),
    LABEL(KEY_AGAIN),
    LABEL(KEY_PROPS),
    LABEL(KEY_UNDO),
    LABEL(KEY_FRONT),
    LABEL(KEY_COPY),
    LABEL(KEY_OPEN),
    LABEL(KEY_PASTE),
    LABEL(KEY_FIND),
    LABEL(KEY_CUT),
    LABEL(KEY_HELP),
    LABEL(KEY_MENU),
    LABEL(KEY_CALC),
    LABEL(KEY_SETUP),
    LABEL(KEY_SLEEP),
    LABEL(KEY_WAKEUP),
    LABEL(KEY_FILE),
    LABEL(KEY_SENDFILE),
    LABEL(KEY_DELETEFILE),
    LABEL(KEY_XFER),
    LABEL(KEY_PROG1),
    LABEL(KEY_PROG2),
    LABEL(KEY_WWW),
    LABEL(KEY_MSDOS),
    LABEL(KEY_COFFEE),
    LABEL(KEY_SCREENLOCK),
    LABEL(KEY_DIRECTION),
    LABEL(KEY_CYCLEWINDOWS),
    LABEL(KEY_MAIL),
    LABEL(KEY_BOOKMARKS),
    LABEL(KEY_COMPUTER),
    LABEL(KEY_BACK),
    LABEL(KEY_FORWARD),
    LABEL(KEY_CLOSECD),
    LABEL(KEY_EJECTCD),
    LABEL(KEY_EJECTCLOSECD),
    LABEL(KEY_NEXTSONG),
    LABEL(KEY_PLAYPAUSE),
    LABEL(KEY_PREVIOUSSONG),
    LABEL(KEY_STOPCD),
    LABEL(KEY_RECORD),
    LABEL(KEY_REWIND),
    LABEL(KEY_PHONE),
    LABEL(KEY_ISO),
    LABEL(KEY_CONFIG),
    LABEL(KEY_HOMEPAGE),
    LABEL(KEY_REFRESH),
    LABEL(KEY_EXIT),
    LABEL(KEY_MOVE),
    LABEL(KEY_EDIT),
    LABEL(KEY_SCROLLUP),
    LABEL(KEY_SCROLLDOWN),
    LABEL(KEY_KPLEFTPAREN),
    LABEL(KEY_KPRIGHTPAREN),
    LABEL(KEY_NEW),
    LABEL(KEY_REDO),
    LABEL(KEY_F13),
    LABEL(KEY_F14),
    LABEL(KEY_F15),
    LABEL(KEY_F16),
    LABEL(KEY_F17),
    LABEL(KEY_F18),
    LABEL(KEY_F19),
    LABEL(KEY_F20),
    LABEL(KEY_F21),
    LABEL(KEY_F22),
    LABEL(KEY_F23),
    LABEL(KEY_F24),
    LABEL(KEY_PLAYCD),
    LABEL(KEY_PAUSECD),
    LABEL(KEY_PROG3),
    LABEL(KEY_PROG4),
    LABEL(KEY_DASHBOARD),
    LABEL(KEY_SUSPEND),
    LABEL(KEY_CLOSE),
    LABEL(KEY_PLAY),
    LABEL(KEY_FASTFORWARD),
    LABEL(KEY_BASSBOOST),
    LABEL(KEY_PRINT),
    LABEL(KEY_HP),
    LABEL(KEY_CAMERA),
    LABEL(KEY_SOUND),
    LABEL(KEY_QUESTION),
    LABEL(KEY_EMAIL),
    LABEL(KEY_CHAT),
    LABEL(KEY_SEARCH),
    LABEL(KEY_CONNECT),
    LABEL(KEY_FINANCE),
    LABEL(KEY_SPORT),
    LABEL(KEY_SHOP),
    LABEL(KEY_ALTERASE),
    LABEL(KEY_CANCEL),
    LABEL(KEY_BRIGHTNESSDOWN),
    LABEL(KEY_BRIGHTNESSUP),
    LABEL(KEY_MEDIA),
    LABEL(KEY_SWITCHVIDEOMODE),
    LABEL(KEY_KBDILLUMTOGGLE),
    LABEL(KEY_KBDILLUMDOWN),
    LABEL(KEY_KBDILLUMUP),
    LABEL(KEY_SEND),
    LABEL(KEY_REPLY),
    LABEL(KEY_FORWARDMAIL),
    LABEL(KEY_SAVE),
    LABEL(KEY_DOCUMENTS),
    LABEL(KEY_BATTERY),
    LABEL(KEY_BLUETOOTH),
    LABEL(KEY_WLAN),
    LABEL(KEY_UWB),
    LABEL(KEY_UNKNOWN),
    LABEL(KEY_VIDEO_NEXT),
    LABEL(KEY_VIDEO_PREV),
    LABEL(KEY_BRIGHTNESS_CYCLE),
    LABEL(KEY_BRIGHTNESS_ZERO),
    LABEL(KEY_DISPLAY_OFF),
    LABEL(KEY_WIMAX),
    LABEL(KEY_RFKILL),
    LABEL(BTN_0),
    LABEL(BTN_1),
    LABEL(BTN_2),
    LABEL(BTN_3),
    LABEL(BTN_4),
    LABEL(BTN_5),
    LABEL(BTN_6),
    LABEL(BTN_7),
    LABEL(BTN_8),
    LABEL(BTN_9),
    LABEL(BTN_LEFT),
    LABEL(BTN_RIGHT),
    LABEL(BTN_MIDDLE),
    LABEL(BTN_SIDE),
    LABEL(BTN_EXTRA),
    LABEL(BTN_FORWARD),
    LABEL(BTN_BACK),
    LABEL(BTN_TASK),
    LABEL(BTN_JOYSTICK),
    LABEL(BTN_TRIGGER),
    LABEL(BTN_THUMB),
    LABEL(BTN_THUMB2),
    LABEL(BTN_TOP),
    LABEL(BTN_TOP2),
    LABEL(BTN_PINKIE),
    LABEL(BTN_BASE),
    LABEL(BTN_BASE2),
    LABEL(BTN_BASE3),
    LABEL(BTN_BASE4),
    LABEL(BTN_BASE5),
    LABEL(BTN_BASE6),
    LABEL(BTN_DEAD),
    LABEL(BTN_A),
    LABEL(BTN_B),
    LABEL(BTN_C),
    LABEL(BTN_X),
    LABEL(BTN_Y),
    LABEL(BTN_Z),
    LABEL(BTN_TL),
    LABEL(BTN_TR),
    LABEL(BTN_TL2),
    LABEL(BTN_TR2),
    LABEL(BTN_SELECT),
    LABEL(BTN_START),
    LABEL(BTN_MODE),
    LABEL(BTN_THUMBL),
    LABEL(BTN_THUMBR),
    LABEL(BTN_TOOL_PEN),
    LABEL(BTN_TOOL_RUBBER),
    LABEL(BTN_TOOL_BRUSH),
    LABEL(BTN_TOOL_PENCIL),
    LABEL(BTN_TOOL_AIRBRUSH),
    LABEL(BTN_TOOL_FINGER),
    LABEL(BTN_TOOL_MOUSE),
    LABEL(BTN_TOOL_LENS),
    LABEL(BTN_TOUCH),
    LABEL(BTN_STYLUS),
    LABEL(BTN_STYLUS2),
    LABEL(BTN_TOOL_DOUBLETAP),
    LABEL(BTN_TOOL_TRIPLETAP),
    LABEL(BTN_TOOL_QUADTAP),
    LABEL(BTN_GEAR_DOWN),
    LABEL(BTN_GEAR_UP),
    LABEL(KEY_OK),
    LABEL(KEY_SELECT),
    LABEL(KEY_GOTO),
    LABEL(KEY_CLEAR),
    LABEL(KEY_POWER2),
    LABEL(KEY_OPTION),
    LABEL(KEY_INFO),
    LABEL(KEY_TIME),
    LABEL(KEY_VENDOR),
    LABEL(KEY_ARCHIVE),
    LABEL(KEY_PROGRAM),
    LABEL(KEY_CHANNEL),
    LABEL(KEY_FAVORITES),
    LABEL(KEY_EPG),
    LABEL(KEY_PVR),
    LABEL(KEY_MHP),
    LABEL(KEY_LANGUAGE),
    LABEL(KEY_TITLE),
    LABEL(KEY_SUBTITLE),
    LABEL(KEY_ANGLE),
    LABEL(KEY_ZOOM),
    LABEL(KEY_MODE),
    LABEL(KEY_KEYBOARD),
    LABEL(KEY_SCREEN),
    LABEL(KEY_PC),
    LABEL(KEY_TV),
    LABEL(KEY_TV2),
    LABEL(KEY_VCR),
    LABEL(KEY_VCR2),
    LABEL(KEY_SAT),
    LABEL(KEY_SAT2),
    LABEL(KEY_CD),
    LABEL(KEY_TAPE),
    LABEL(KEY_RADIO),
    LABEL(KEY_TUNER),
    LABEL(KEY_PLAYER),
    LABEL(KEY_TEXT),
    LABEL(KEY_DVD),
    LABEL(KEY_AUX),
    LABEL(KEY_MP3),
    LABEL(KEY_AUDIO),
    LABEL(KEY_VIDEO),
    LABEL(KEY_DIRECTORY),
    LABEL(KEY_LIST),
    LABEL(KEY_MEMO),
    LABEL(KEY_CALENDAR),
    LABEL(KEY_RED),
    LABEL(KEY_GREEN),
    LABEL(KEY_YELLOW),
    LABEL(KEY_BLUE),
    LABEL(KEY_CHANNELUP),
    LABEL(KEY_CHANNELDOWN),
    LABEL(KEY_FIRST),
    LABEL(KEY_LAST),
    LABEL(KEY_AB),
    LABEL(KEY_NEXT),
    LABEL(KEY_RESTART),
    LABEL(KEY_SLOW),
    LABEL(KEY_SHUFFLE),
    LABEL(KEY_BREAK),
    LABEL(KEY_PREVIOUS),
    LABEL(KEY_DIGITS),
    LABEL(KEY_TEEN),
    LABEL(KEY_TWEN),
    LABEL(KEY_VIDEOPHONE),
    LABEL(KEY_GAMES),
    LABEL(KEY_ZOOMIN),
    LABEL(KEY_ZOOMOUT),
    LABEL(KEY_ZOOMRESET),
    LABEL(KEY_WORDPROCESSOR),
    LABEL(KEY_EDITOR),
    LABEL(KEY_SPREADSHEET),
    LABEL(KEY_GRAPHICSEDITOR),
    LABEL(KEY_PRESENTATION),
    LABEL(KEY_DATABASE),
    LABEL(KEY_NEWS),
    LABEL(KEY_VOICEMAIL),
    LABEL(KEY_ADDRESSBOOK),
    LABEL(KEY_MESSENGER),
    LABEL(KEY_DISPLAYTOGGLE),
    LABEL(KEY_SPELLCHECK),
    LABEL(KEY_LOGOFF),
    LABEL(KEY_DOLLAR),
    LABEL(KEY_EURO),
    LABEL(KEY_FRAMEBACK),
    LABEL(KEY_FRAMEFORWARD),
    LABEL(KEY_CONTEXT_MENU),
    LABEL(KEY_MEDIA_REPEAT),
    LABEL(KEY_10CHANNELSUP),
    LABEL(KEY_10CHANNELSDOWN),
    LABEL(KEY_IMAGES),
    LABEL(KEY_DEL_EOL),
    LABEL(KEY_DEL_EOS),
    LABEL(KEY_INS_LINE),
    LABEL(KEY_DEL_LINE),
    LABEL(KEY_FN),
    LABEL(KEY_FN_ESC),
    LABEL(KEY_FN_F1),
    LABEL(KEY_FN_F2),
    LABEL(KEY_FN_F3),
    LABEL(KEY_FN_F4),
    LABEL(KEY_FN_F5),
    LABEL(KEY_FN_F6),
    LABEL(KEY_FN_F7),
    LABEL(KEY_FN_F8),
    LABEL(KEY_FN_F9),
    LABEL(KEY_FN_F10),
    LABEL(KEY_FN_F11),
    LABEL(KEY_FN_F12),
    LABEL(KEY_FN_1),
    LABEL(KEY_FN_2),
    LABEL(KEY_FN_D),
    LABEL(KEY_FN_E),
    LABEL(KEY_FN_F),
    LABEL(KEY_FN_S),
    LABEL(KEY_FN_B),
    LABEL(KEY_BRL_DOT1),
    LABEL(KEY_BRL_DOT2),
    LABEL(KEY_BRL_DOT3),
    LABEL(KEY_BRL_DOT4),
    LABEL(KEY_BRL_DOT5),
    LABEL(KEY_BRL_DOT6),
    LABEL(KEY_BRL_DOT7),
    LABEL(KEY_BRL_DOT8),
    LABEL(KEY_BRL_DOT9),
    LABEL(KEY_BRL_DOT10),
    LABEL(KEY_NUMERIC_0),
    LABEL(KEY_NUMERIC_1),
    LABEL(KEY_NUMERIC_2),
    LABEL(KEY_NUMERIC_3),
    LABEL(KEY_NUMERIC_4),
    LABEL(KEY_NUMERIC_5),
    LABEL(KEY_NUMERIC_6),
    LABEL(KEY_NUMERIC_7),
    LABEL(KEY_NUMERIC_8),
    LABEL(KEY_NUMERIC_9),
    LABEL(KEY_NUMERIC_STAR),
    LABEL(KEY_NUMERIC_POUND),
    LABEL(KEY_CAMERA_FOCUS),
    LABEL(KEY_WPS_BUTTON),
    LABEL(KEY_TOUCHPAD_TOGGLE),
    LABEL(KEY_TOUCHPAD_ON),
    LABEL(KEY_TOUCHPAD_OFF),
    LABEL(KEY_CAMERA_ZOOMIN),
    LABEL(KEY_CAMERA_ZOOMOUT),
    LABEL(KEY_CAMERA_UP),
    LABEL(KEY_CAMERA_DOWN),
    LABEL(KEY_CAMERA_LEFT),
    LABEL(KEY_CAMERA_RIGHT),
    LABEL(BTN_TRIGGER_HAPPY1),
    LABEL(BTN_TRIGGER_HAPPY2),
    LABEL(BTN_TRIGGER_HAPPY3),
    LABEL(BTN_TRIGGER_HAPPY4),
    LABEL(BTN_TRIGGER_HAPPY5),
    LABEL(BTN_TRIGGER_HAPPY6),
    LABEL(BTN_TRIGGER_HAPPY7),
    LABEL(BTN_TRIGGER_HAPPY8),
    LABEL(BTN_TRIGGER_HAPPY9),
    LABEL(BTN_TRIGGER_HAPPY10),
    LABEL(BTN_TRIGGER_HAPPY11),
    LABEL(BTN_TRIGGER_HAPPY12),
    LABEL(BTN_TRIGGER_HAPPY13),
    LABEL(BTN_TRIGGER_HAPPY14),
    LABEL(BTN_TRIGGER_HAPPY15),
    LABEL(BTN_TRIGGER_HAPPY16),
    LABEL(BTN_TRIGGER_HAPPY17),
    LABEL(BTN_TRIGGER_HAPPY18),
    LABEL(BTN_TRIGGER_HAPPY19),
    LABEL(BTN_TRIGGER_HAPPY20),
    LABEL(BTN_TRIGGER_HAPPY21),
    LABEL(BTN_TRIGGER_HAPPY22),
    LABEL(BTN_TRIGGER_HAPPY23),
    LABEL(BTN_TRIGGER_HAPPY24),
    LABEL(BTN_TRIGGER_HAPPY25),
    LABEL(BTN_TRIGGER_HAPPY26),
    LABEL(BTN_TRIGGER_HAPPY27),
    LABEL(BTN_TRIGGER_HAPPY28),
    LABEL(BTN_TRIGGER_HAPPY29),
    LABEL(BTN_TRIGGER_HAPPY30),
    LABEL(BTN_TRIGGER_HAPPY31),
    LABEL(BTN_TRIGGER_HAPPY32),
    LABEL(BTN_TRIGGER_HAPPY33),
    LABEL(BTN_TRIGGER_HAPPY34),
    LABEL(BTN_TRIGGER_HAPPY35),
    LABEL(BTN_TRIGGER_HAPPY36),
    LABEL(BTN_TRIGGER_HAPPY37),
    LABEL(BTN_TRIGGER_HAPPY38),
    LABEL(BTN_TRIGGER_HAPPY39),
    LABEL(BTN_TRIGGER_HAPPY40),
    LABEL_END,
};
static struct label rel_labels[] = {
    LABEL(REL_X),      LABEL(REL_Y),    LABEL(REL_Z),     LABEL(REL_RX),   LABEL(REL_RY), LABEL(REL_RZ),
    LABEL(REL_HWHEEL), LABEL(REL_DIAL), LABEL(REL_WHEEL), LABEL(REL_MISC), LABEL_END,
};
static struct label abs_labels[] = {
    LABEL(ABS_X),
    LABEL(ABS_Y),
    LABEL(ABS_Z),
    LABEL(ABS_RX),
    LABEL(ABS_RY),
    LABEL(ABS_RZ),
    LABEL(ABS_THROTTLE),
    LABEL(ABS_RUDDER),
    LABEL(ABS_WHEEL),
    LABEL(ABS_GAS),
    LABEL(ABS_BRAKE),
    LABEL(ABS_HAT0X),
    LABEL(ABS_HAT0Y),
    LABEL(ABS_HAT1X),
    LABEL(ABS_HAT1Y),
    LABEL(ABS_HAT2X),
    LABEL(ABS_HAT2Y),
    LABEL(ABS_HAT3X),
    LABEL(ABS_HAT3Y),
    LABEL(ABS_PRESSURE),
    LABEL(ABS_DISTANCE),
    LABEL(ABS_TILT_X),
    LABEL(ABS_TILT_Y),
    LABEL(ABS_TOOL_WIDTH),
    LABEL(ABS_VOLUME),
    LABEL(ABS_MISC),
    LABEL(ABS_MT_SLOT),
    LABEL(ABS_MT_TOUCH_MAJOR),
    LABEL(ABS_MT_TOUCH_MINOR),
    LABEL(ABS_MT_WIDTH_MAJOR),
    LABEL(ABS_MT_WIDTH_MINOR),
    LABEL(ABS_MT_ORIENTATION),
    LABEL(ABS_MT_POSITION_X),
    LABEL(ABS_MT_POSITION_Y),
    LABEL(ABS_MT_TOOL_TYPE),
    LABEL(ABS_MT_BLOB_ID),
    LABEL(ABS_MT_TRACKING_ID),
    LABEL(ABS_MT_PRESSURE),
    LABEL(ABS_MT_DISTANCE),
    LABEL_END,
};
static struct label sw_labels[] = {
    LABEL(SW_LID),
    LABEL(SW_TABLET_MODE),
    LABEL(SW_HEADPHONE_INSERT),
    LABEL(SW_RFKILL_ALL),
    LABEL(SW_RADIO),
    LABEL(SW_MICROPHONE_INSERT),
    LABEL(SW_DOCK),
    LABEL(SW_LINEOUT_INSERT),
    LABEL(SW_JACK_PHYSICAL_INSERT),
    LABEL(SW_VIDEOOUT_INSERT),
    LABEL(SW_CAMERA_LENS_COVER),
    LABEL(SW_KEYPAD_SLIDE),
    LABEL(SW_FRONT_PROXIMITY),
    LABEL(SW_ROTATE_LOCK),
    LABEL_END,
};
static struct label msc_labels[] = {
    LABEL(MSC_SERIAL), LABEL(MSC_PULSELED), LABEL(MSC_GESTURE), LABEL(MSC_RAW), LABEL(MSC_SCAN), LABEL_END,
};
static struct label led_labels[] = {
    LABEL(LED_NUML),    LABEL(LED_CAPSL), LABEL(LED_SCROLLL), LABEL(LED_COMPOSE), LABEL(LED_KANA),     LABEL(LED_SLEEP),
    LABEL(LED_SUSPEND), LABEL(LED_MUTE),  LABEL(LED_MISC),    LABEL(LED_MAIL),    LABEL(LED_CHARGING), LABEL_END,
};
static struct label rep_labels[] = {
    LABEL(REP_DELAY),
    LABEL(REP_PERIOD),
    LABEL_END,
};
static struct label snd_labels[] = {
    LABEL(SND_CLICK),
    LABEL(SND_BELL),
    LABEL(SND_TONE),
    LABEL_END,
};
static struct label id_labels[] = {
    LABEL(ID_BUS), LABEL(ID_VENDOR), LABEL(ID_PRODUCT), LABEL(ID_VERSION), LABEL_END,
};
static struct label bus_labels[] = {
    LABEL(BUS_PCI),      LABEL(BUS_ISAPNP),  LABEL(BUS_USB),   LABEL(BUS_HIL),   LABEL(BUS_BLUETOOTH),
    LABEL(BUS_VIRTUAL),  LABEL(BUS_ISA),     LABEL(BUS_I8042), LABEL(BUS_XTKBD), LABEL(BUS_RS232),
    LABEL(BUS_GAMEPORT), LABEL(BUS_PARPORT), LABEL(BUS_AMIGA), LABEL(BUS_ADB),   LABEL(BUS_I2C),
    LABEL(BUS_HOST),     LABEL(BUS_GSC),     LABEL(BUS_ATARI), LABEL(BUS_SPI),   LABEL_END,
};
static struct label mt_tool_labels[] = {
    LABEL(MT_TOOL_FINGER),
    LABEL(MT_TOOL_PEN),
    LABEL(MT_TOOL_MAX),
    LABEL_END,
};
static struct label ff_status_labels[] = {
    LABEL(FF_STATUS_STOPPED),
    LABEL(FF_STATUS_PLAYING),
    LABEL(FF_STATUS_MAX),
    LABEL_END,
};
static struct label ff_labels[] = {
    LABEL(FF_RUMBLE),     LABEL(FF_PERIODIC), LABEL(FF_CONSTANT), LABEL(FF_SPRING), LABEL(FF_FRICTION),
    LABEL(FF_DAMPER),     LABEL(FF_INERTIA),  LABEL(FF_RAMP),     LABEL(FF_SQUARE), LABEL(FF_TRIANGLE),
    LABEL(FF_SINE),       LABEL(FF_SAW_UP),   LABEL(FF_SAW_DOWN), LABEL(FF_CUSTOM), LABEL(FF_GAIN),
    LABEL(FF_AUTOCENTER), LABEL_END,
};
static struct label key_value_labels[] = {
    {"UP", 0},
    {"DOWN", 1},
    {"REPEAT", 2},
    LABEL_END,
};

static struct pollfd *ufds;
static char **device_names;
static int nfds;
enum
{
    PRINT_DEVICE_ERRORS = 1U << 0,
    PRINT_DEVICE = 1U << 1,
    PRINT_DEVICE_NAME = 1U << 2,
    PRINT_DEVICE_INFO = 1U << 3,
    PRINT_VERSION = 1U << 4,
    PRINT_POSSIBLE_EVENTS = 1U << 5,
    PRINT_INPUT_PROPS = 1U << 6,
    PRINT_HID_DESCRIPTOR = 1U << 7,
    PRINT_ALL_INFO = (1U << 8) - 1,
    PRINT_LABELS = 1U << 16,
};
static const char *get_label(const struct label *labels, int value)
{
    while (labels->name && value != labels->value)
    {
        labels++;
    }
    return labels->name;
}
static int print_input_props(int fd)
{
    uint8_t bits[INPUT_PROP_CNT / 8];
    int i, j;
    int res;
    int count;
    const char *bit_label;
    printf("  input props:\n");
    res = ioctl(fd, EVIOCGPROP(sizeof(bits)), bits);
    if (res < 0)
    {
        printf("    <not available\n");
        return 1;
    }
    count = 0;
    for (i = 0; i < res; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (bits[i] & 1 << j)
            {
                bit_label = get_label(input_prop_labels, i * 8 + j);
                if (bit_label)
                    printf("    %s\n", bit_label);
                else
                    printf("    %04x\n", i * 8 + j);
                count++;
            }
        }
    }
    if (!count)
        printf("    <none>\n");
    return 0;
}
static int print_possible_events(int fd, int print_flags, tabsmsub &submap, tabsmsub &submap2)
{
    uint8_t *bits = NULL;
    ssize_t bits_size = 0;
    const char *label;
    int i, j, k;
    int res, res2;
    struct label *bit_labels;
    const char *bit_label;
    // printf("  events:\n");
    for (i = EV_KEY; i <= EV_MAX; i++)
    { // skip EV_SYN since we cannot query its available codes
        int count = 0;
        while (1)
        {
            res = ioctl(fd, EVIOCGBIT(i, bits_size), bits);
            if (res < bits_size)
                break;
            bits_size = res + 16;
            bits = (uint8_t *)realloc(bits, bits_size * 2);
            if (bits == NULL)
            {
                fprintf(stderr, "failed to allocate buffer of size %d\n", (int)bits_size);
                return 1;
            }
        }
        res2 = 0;
        switch (i)
        {
        case EV_KEY:
            res2 = ioctl(fd, EVIOCGKEY(res), bits + bits_size);
            label = "KEY";
            bit_labels = key_labels;
            break;
        case EV_REL:
            label = "REL";
            bit_labels = rel_labels;
            break;
        case EV_ABS:
            label = "ABS";
            bit_labels = abs_labels;
            break;
        case EV_MSC:
            label = "MSC";
            bit_labels = msc_labels;
            break;
        case EV_LED:
            res2 = ioctl(fd, EVIOCGLED(res), bits + bits_size);
            label = "LED";
            bit_labels = led_labels;
            break;
        case EV_SND:
            res2 = ioctl(fd, EVIOCGSND(res), bits + bits_size);
            label = "SND";
            bit_labels = snd_labels;
            break;
        case EV_SW:
            res2 = ioctl(fd, EVIOCGSW(bits_size), bits + bits_size);
            label = "SW ";
            bit_labels = sw_labels;
            break;
        case EV_REP:
            label = "REP";
            bit_labels = rep_labels;
            break;
        case EV_FF:
            label = "FF ";
            bit_labels = ff_labels;
            break;
        case EV_PWR:
            label = "PWR";
            bit_labels = NULL;
            break;
        case EV_FF_STATUS:
            label = "FFS";
            bit_labels = ff_status_labels;
            break;
        default:
            res2 = 0;
            label = "???";
            bit_labels = NULL;
        }
        for (j = 0; j < res; j++)
        {
            for (k = 0; k < 8; k++)
                if (bits[j] & 1 << k)
                {
                    // char down;
                    //  if (j < res2 && (bits[j + bits_size] & 1 << k))
                    //      down = '*';
                    //  else
                    //      down = ' ';
                    if (count == 0)
                    {
                        // printf("    %s (%04x):", label, i);
                        submap[i];
                        submap2[i];
                    }

                    // else if ((count & (print_flags & PRINT_LABELS ? 0x3 : 0x7)) == 0 || i == EV_ABS)
                    //     printf("\n               ");
                    // if (bit_labels && (print_flags & PRINT_LABELS))
                    //{
                    //     bit_label = get_label(bit_labels, j * 8 + k);
                    //     if (bit_label)
                    //         printf(" %.20s%c%*s", bit_label, down, 20 - (int)strlen(bit_label), "");
                    //     else
                    //         printf(" %04x%c                ", j * 8 + k, down);
                    // }
                    // else
                    //{
                    //     printf(" %04x%c", j * 8 + k, down);
                    //     // submap[i][j * 8 + k];
                    // }
                    if (i == EV_ABS)
                    {
                        struct input_absinfo abs;
                        if (ioctl(fd, EVIOCGABS(j * 8 + k), &abs) == 0)
                        {
                            // printf(" : value %d, min %d, max %d, fuzz %d, flat %d, resolution %d", abs.value,
                            //        abs.minimum, abs.maximum, abs.fuzz, abs.flat, abs.resolution);
                            submap[i][j * 8 + k] = abs.maximum;
                            submap2[i][j * 8 + k] = abs.value;
                        }
                    }
                    count++;
                }
        }
        // if (count)
        ///    printf("\n");
    }
    free(bits);
    return 0;
}
static void print_event(int type, int code, int value, int print_flags, int screen_width, int screen_height,
                        tabsmsub &submap)
{
    const char *type_label, *code_label, *value_label;

    type_label = get_label(ev_labels, type);
    code_label = NULL;
    value_label = NULL;
    switch (type)
    {
    case EV_SYN:
        code_label = get_label(syn_labels, code);
        break;
    case EV_KEY:
        code_label = get_label(key_labels, code);
        value_label = get_label(key_value_labels, value);
        break;
    case EV_REL:
        code_label = get_label(rel_labels, code);
        break;
    case EV_ABS:
        code_label = get_label(abs_labels, code);
        switch (code)
        {
        case ABS_MT_TOOL_TYPE:
            value_label = get_label(mt_tool_labels, value);
        }
        break;
    case EV_MSC:
        code_label = get_label(msc_labels, code);
        break;
    case EV_LED:
        code_label = get_label(led_labels, code);
        break;
    case EV_SND:
        code_label = get_label(snd_labels, code);
        break;
    case EV_SW:
        code_label = get_label(sw_labels, code);
        break;
    case EV_REP:
        code_label = get_label(rep_labels, code);
        break;
    case EV_FF:
        code_label = get_label(ff_labels, code);
        break;
    case EV_FF_STATUS:
        code_label = get_label(ff_status_labels, code);
        break;
    }
}
static void print_hid_descriptor(int bus, int vendor, int product)
{
    const char *dirname = "/sys/kernel/debug/hid";
    char prefix[16];
    DIR *dir;
    struct dirent *de;
    char filename[PATH_MAX];
    FILE *file;
    char line[2048];
    snprintf(prefix, sizeof(prefix), "%04X:%04X:%04X.", bus, vendor, product);
    dir = opendir(dirname);
    if (dir == NULL)
        return;
    while ((de = readdir(dir)))
    {
        if (strstr(de->d_name, prefix) == de->d_name)
        {
            snprintf(filename, sizeof(filename), "%s/%s/rdesc", dirname, de->d_name);
            file = fopen(filename, "r");
            if (file)
            {
                printf("  HID descriptor: %s\n\n", de->d_name);
                while (fgets(line, sizeof(line), file))
                {
                    fputs("    ", stdout);
                    fputs(line, stdout);
                }
                fclose(file);
                puts("");
            }
        }
    }
    closedir(dir);
}
static int open_device(const char *device, int print_flags)
{
    int version;
    int fd;
    struct pollfd *new_ufds;
    char **new_device_names;
    char name[80];
    char location[80];
    char idstr[80];
    struct input_id id;
    fd = open(device, O_RDWR);
    if (fd < 0)
    {
        if (print_flags & PRINT_DEVICE_ERRORS)
        {
            // fprintf(stderr, "could not open %s, %s\n", device, strerror(errno));
        }
        return -1;
    }

    if (ioctl(fd, EVIOCGVERSION, &version))
    {
        if (print_flags & PRINT_DEVICE_ERRORS)
        {
            // fprintf(stderr, "could not get driver version for %s, %s\n", device, strerror(errno));
        }
        return -1;
    }
    if (ioctl(fd, EVIOCGID, &id))
    {
        if (print_flags & PRINT_DEVICE_ERRORS)
        {
            // fprintf(stderr, "could not get driver id for %s, %s\n", device, strerror(errno));
        }
        return -1;
    }
    name[sizeof(name) - 1] = '\0';
    location[sizeof(location) - 1] = '\0';
    idstr[sizeof(idstr) - 1] = '\0';
    if (ioctl(fd, EVIOCGNAME(sizeof(name) - 1), &name) < 1)
    {
        // fprintf(stderr, "could not get device name for %s, %s\n", device, strerror(errno));
        name[0] = '\0';
    }
    if (ioctl(fd, EVIOCGPHYS(sizeof(location) - 1), &location) < 1)
    {
        // fprintf(stderr, "could not get location for %s, %s\n", device, strerror(errno));
        location[0] = '\0';
    }
    if (ioctl(fd, EVIOCGUNIQ(sizeof(idstr) - 1), &idstr) < 1)
    {
        // fprintf(stderr, "could not get idstring for %s, %s\n", device, strerror(errno));
        idstr[0] = '\0';
    }
    new_ufds = (struct pollfd *)realloc(ufds, sizeof(ufds[0]) * (nfds + 1));
    if (new_ufds == NULL)
    {
        fprintf(stderr, "out of memory\n");
        return -1;
    }
    ufds = new_ufds;
    new_device_names = (char **)realloc(device_names, sizeof(device_names[0]) * (nfds + 1));
    if (new_device_names == NULL)
    {
        fprintf(stderr, "out of memory\n");
        return -1;
    }
    device_names = new_device_names;
    absmap[nfds];
    position_now[nfds];
    print_possible_events(fd, print_flags, absmap[nfds], position_now[nfds]);
    ufds[nfds].fd = fd;
    ufds[nfds].events = POLLIN;
    device_names[nfds] = strdup(device);
    device_mapping[nfds] = device;
    nfds++;
    return 0;
}
int close_device(const char *device, int print_flags)
{
    int i;
    for (i = 1; i < nfds; i++)
    {
        if (strcmp(device_names[i], device) == 0)
        {
            int count = nfds - i - 1;
            free(device_names[i]);
            memmove(device_names + i, device_names + i + 1, sizeof(device_names[0]) * count);
            memmove(ufds + i, ufds + i + 1, sizeof(ufds[0]) * count);
            nfds--;
            return 0;
        }
    }
    if (print_flags & PRINT_DEVICE_ERRORS)
    {
        fprintf(stderr, "remote device: %s not found\n", device);
    }
    return -1;
}
static int read_notify(const char *dirname, int nfd, int print_flags)
{
    int res;
    char devname[PATH_MAX];
    char *filename;
    char event_buf[512];
    int event_size;
    int event_pos = 0;
    struct inotify_event *event;
    res = read(nfd, event_buf, sizeof(event_buf));
    if (res < (int)sizeof(*event))
    {
        if (errno == EINTR)
            return 0;
        fprintf(stderr, "could not get event, %s\n", strerror(errno));
        return 1;
    }
    // printf("got %d bytes of event information\n", res);
    strcpy(devname, dirname);
    filename = devname + strlen(devname);
    *filename++ = '/';
    while (res >= (int)sizeof(*event))
    {
        event = (struct inotify_event *)(event_buf + event_pos);
        // printf("%d: %08x \"%s\"\n", event->wd, event->mask, event->len ? event->name : "");
        if (event->len)
        {
            strcpy(filename, event->name);
            if (event->mask & IN_CREATE)
            {
                open_device(devname, print_flags);
            }
            else
            {
                close_device(devname, print_flags);
            }
        }
        event_size = sizeof(*event) + event->len;
        res -= event_size;
        event_pos += event_size;
    }
    return 0;
}
static int scan_dir(const char *dirname, int print_flags)
{
    char devname[PATH_MAX];
    char *filename;
    DIR *dir;
    struct dirent *de;
    dir = opendir(dirname);
    if (dir == NULL)
        return -1;
    strcpy(devname, dirname);
    filename = devname + strlen(devname);
    *filename++ = '/';
    while ((de = readdir(dir)))
    {
        if (de->d_name[0] == '.' && (de->d_name[1] == '\0' || (de->d_name[1] == '.' && de->d_name[2] == '\0')))
            continue;
        strcpy(filename, de->d_name);
        open_device(devname, print_flags);
    }
    closedir(dir);
    return 0;
}

std::vector<std::pair<int, int>> static bresenhamLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    int e2 = 0;
    std::vector<std::pair<int, int>> points;
    points.reserve((std::max(dx, dy) + 1) * 4);

    for (;;)
    {
        points.emplace_back(std::make_pair(x1, y1));

        if (x1 == x2 && y1 == y2)
        {
            break;
        }

        e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
    return points;
}

static int execute_sendevent(std::string &device_to_open, std::vector<std::pair<input_event, uint64_t>> &commands,
                             bool debug_mode = false)
{
    int i;
    int fd;
    int ret;
    int version;
    // struct input_event event{};
    fd = open(device_to_open.c_str(), O_RDWR);
    if (fd < 0)
    {
        std::cerr << "could not open " << device_to_open << '\n';
        return 1;
    }
    if (ioctl(fd, EVIOCGVERSION, &version))
    {
        std::cerr << "could not get driver version for " << device_to_open << '\n';
        return 1;
    }

    for (const auto &[my_event, my_sleeptime] : commands)
    {
        if (debug_mode)
        {
            // std::cerr << "sendevent " << device_to_open << " " << (my_event.type) << " " << (my_event.code) << " " <<
            // (my_event.value) << '\n';

            fprintf(stderr, "sendevent %s %d %d %d\n", device_to_open.c_str(), my_event.type, my_event.code,
                    my_event.value);
        }
        ret = write(fd, &my_event, sizeof(my_event));
        if (debug_mode && (ret < 0))
        {
            std::cerr << "could not send event " << device_to_open << '\n';
        }
        if (my_sleeptime > 0)
        {
            if (debug_mode)
            {
                std::cerr << "sleeping " << my_sleeptime << " ms" << '\n';
            }
            sleep_us(my_sleeptime);
        }
    }
    return 0;
}

template <typename T> std::vector<T> logsplit_fill(std::vector<T> &lst)
{
    std::vector<std::vector<T>> result;
    result.reserve(ceil(sqrt(lst.size())) + 1);
    auto it = lst.begin();
    int n = 0;

    while (it != lst.end())
    {
        std::vector<T> chunk;
        chunk.reserve(n + 1);
        chunk.emplace_back(*it);
        ++it;

        for (int i{}; i < n && it != lst.end(); ++i)
        {
            chunk.emplace_back(*it);
            ++it;
        }

        result.emplace_back(chunk);
        ++n;
    }
    std::vector<T> fillit;
    size_t start = 1;
    size_t reservesize = 0;
    std::vector<size_t> multipliervec;
    multipliervec.reserve(result.size());
    for (size_t i{}; i < result.size(); i++)
    {
        multipliervec.emplace_back(start);
        reservesize += result[i].size() * start;
        start++;
    }
    // std::reverse(multipliervec.begin(), multipliervec.end());
    fillit.reserve(reservesize);
    for (size_t i{}; i < result.size(); i++)
    {
        for (size_t j{}; j < result[i].size(); j++)
        {
            for (size_t k{}; k < multipliervec[i]; k++)
            {
                fillit.emplace_back(result[i][j]);
            }
        }
    }

    return fillit;
}

template <typename T> std::vector<T> get_every_n_element_from_vec(std::vector<T> &v, size_t n)
{

    if (v.size() <= 2)
    {
        return v;
    }
    std::vector<T> resultvec;
    resultvec.reserve((v.size() / n) + 3);
    bool got_last{false};
    for (size_t i{}; i < v.size(); i += n)
    {
        resultvec.emplace_back(v[i]);
        if (i + 1 == v.size())
        {
            got_last = true;
        }
    }
    if (!got_last)
    {
        resultvec.emplace_back(v[v.size() - 1]);
    }
    return resultvec;
}
template <typename T> std::vector<T> generate_vec_of_random_numbers(T minimal, T maximal, size_t n)
{
    std::vector<T> v;
    v.reserve(n);

    std::random_device rd;
    std::mt19937 engine(rd());

    if constexpr (std::is_integral<T>::value)
    {
        std::uniform_int_distribution<T> dist(minimal, maximal);
        for (size_t i{}; i < n; i++)
        {
            v.emplace_back(dist(engine));
        }
    }
    else if constexpr (std::is_floating_point<T>::value)
    {
        std::uniform_real_distribution<T> dist(minimal, maximal);
        for (size_t i{}; i < n; i++)
        {
            v.emplace_back(dist(engine));
        }
    }

    return v;
}

void static add_to_vec(bool usefirst, int min_value, int max_value, std::vector<int> &&vadd,
                       std::vector<std::pair<int, int>> &v, int max_abs_value)
{
    for (size_t i{}; i < v.size(); i++)
    {
        if (usefirst && (v[i].first + vadd[i] >= 0) && (v[i].first + vadd[i] <= max_abs_value) && (i != 0) &&
            (i != v.size() - 1))
        {
            v[i].first += vadd[i];
        }
        else if (!usefirst && (v[i].second + vadd[i] >= 0) && (v[i].second + vadd[i] <= max_abs_value) && (i != 0) &&
                 (i != v.size() - 1))
        {
            v[i].second += vadd[i];
        }
    }
}
std::vector<std::pair<input_event, uint64_t>> static get_coords_vector(
    std::vector<mouselike_devices> valid_mouse_devices, std::string &wanted_device, int x, int y, int screen_width,
    int screen_height, uint64_t sleep_time_between_actions, int event_multiply, int do_natual_movement,
    size_t use_every_n_element, int start_x, int start_y, int min_x_variation, int min_y_variation, int max_x_variation,
    int max_y_variation, mouselike_devices &choosen_device, size_t &choosen_device_index, bool create_move_actions)
{
    std::vector<std::pair<input_event, uint64_t>> allinputevents;
    std::vector<std::pair<int, int>> linecoords;
    size_t wanted_device_index{0};
    int device_maximum_screen_value_x{0};
    int device_maximum_screen_value_y{0};
    for (auto &device : valid_mouse_devices)
    {
        if (device.device_path == wanted_device)
        {
            int maximum_screen_value_x{device.max_value_x};
            int maximum_screen_value_y{device.max_value_y};
            double real_destiny_x{(double)maximum_screen_value_x / (double)screen_width * (double)x};
            double real_destiny_y{(double)maximum_screen_value_y / (double)screen_height * (double)y};
            if (start_x >= 0)
            {
                double current_value_x_recalc{(double)maximum_screen_value_x / (double)screen_width * (double)start_x};
                device.current_value_x = (int)current_value_x_recalc;
            }
            if (start_y >= 0)
            {
                double current_value_y_recalc{(double)maximum_screen_value_y / (double)screen_height * (double)start_y};
                device.current_value_y = (int)current_value_y_recalc;
            }
            if (create_move_actions)
            {
                linecoords = bresenhamLine(device.current_value_x, device.current_value_y, int(real_destiny_x),
                                           (int)real_destiny_y);
            }
            device_maximum_screen_value_x = maximum_screen_value_x;
            device_maximum_screen_value_y = maximum_screen_value_y;
            choosen_device = device;
            choosen_device_index = wanted_device_index;
            break;
        }
        wanted_device_index++;
    }
    if (!create_move_actions)
    {
        return allinputevents;
    }
    if (do_natual_movement == 1)
    {
        linecoords = logsplit_fill(linecoords);
    }
    if (use_every_n_element != 1)
    {
        linecoords = get_every_n_element_from_vec(linecoords, use_every_n_element);
    }
    if (min_y_variation != 0 || max_y_variation != 0)
    {
        // std::vector<int> add_to_y{generate_vec_of_random_numbers(min_y_variation, max_y_variation,
        // linecoords.size())};
        add_to_vec(false, 0, screen_height,
                   generate_vec_of_random_numbers(min_y_variation, max_y_variation, linecoords.size()), linecoords,
                   device_maximum_screen_value_y);
    }
    if (min_x_variation != 0 || max_x_variation != 0)
    {
        // std::vector<int> add_to_x{generate_vec_of_random_numbers(min_x_variation, max_x_variation,
        // linecoords.size())};
        add_to_vec(true, 0, screen_width,
                   generate_vec_of_random_numbers(min_x_variation, max_x_variation, linecoords.size()), linecoords,
                   device_maximum_screen_value_x);
    }
    allinputevents.reserve((1 + linecoords.size()) * 3 * event_multiply);
    for (const auto &[myx, myy] : linecoords)
    {
        for (int _t{}; _t < event_multiply; _t++)
        {
            allinputevents.emplace_back(
                std::make_pair(input_event{{0, 0},
                                           valid_mouse_devices[wanted_device_index].event_code,
                                           valid_mouse_devices[wanted_device_index].event_value_1,
                                           myx},
                               sleep_time_between_actions));
            allinputevents.emplace_back(
                std::make_pair(input_event{{0, 0},
                                           valid_mouse_devices[wanted_device_index].event_code,
                                           valid_mouse_devices[wanted_device_index].event_value_2,
                                           myy},
                               sleep_time_between_actions));
            allinputevents.emplace_back(sync_event_no_sleep);
        }
    }
    return allinputevents;
}

template <typename T, typename U> std::ostream &operator<<(std::ostream &os, std::vector<std::pair<T, U>> &v)
{
    if (v.size() == 0)
    {
        os << "[]";
        return os;
    }
    auto it{v.begin()};

    os << '[';
    while (it != v.end() - 1)
    {
        os << "[" << it->first << "," << it->second << "]";
        os << ",";

        it++;
    }
    os << "[" << it->first << "," << it->second << "]";
    os << ']';

    return os;
}

template <typename T> std::ostream &operator<<(std::ostream &os, std::vector<T> &v)
{
    if (v.size() == 0)
    {
        os << "[]";
        return os;
    }
    auto it{v.begin()};

    os << '[';
    while (it != v.end() - 1)
    {
        os << *it;
        os << ",";

        it++;
    }
    os << *it;
    os << ']';

    return os;
}

typedef struct parsed_args
{

    std::string this_file;
    int screen_width;
    int screen_height;
    int x;
    int y;
    uint64_t sleep_time;
    int debug;
    std::string device;
    int event_multiply;
    int natural_movement;
    size_t use_every_n_element;
    int action;
    int start_x;
    int start_y;
    int min_x_variation;
    int min_y_variation;
    int max_x_variation;
    int max_y_variation;
    int print_device_info;
    uint64_t click_duration;
    uint64_t sleep_time_before_left_click;
    uint64_t sleep_time_before_right_click;
    uint64_t sleep_time_before_middle_click;
    uint64_t sleep_time_before_downscroll;
    uint64_t sleep_time_before_upscroll;
    size_t number_of_scrolls;
    uint64_t sleep_time_between_scrolls;
    mouselike_devices choosen_device;
    size_t choosen_device_index;
    bool _screen_width;
    bool _screen_height;
    bool _x;
    bool _y;
    bool _sleep_time;
    bool _debug;
    bool _device;
    bool _event_multiply;
    bool _natural_movement;
    bool _use_every_n_element;
    bool _action;
    bool _start_x;
    bool _start_y;
    bool _min_x_variation;
    bool _min_y_variation;
    bool _max_x_variation;
    bool _max_y_variation;
    bool _print_device_info;
    bool _click_duration;
    bool _sleep_time_before_left_click;
    bool _sleep_time_before_right_click;
    bool _sleep_time_before_middle_click;
    bool _sleep_time_before_downscroll;
    bool _sleep_time_before_upscroll;
    bool _number_of_scrolls;
    bool _sleep_time_between_scrolls;

} p_args;
static constexpr std::string_view On_IRed = "\033[0;101m"; // Red
static constexpr std::string_view Color_Off = "\033[0m";   // Text Reset
static constexpr std::string_view IYellow = "\033[0;93m";  // Yellow

/*


cp /sdcard/sendeventmouse.cpp . && g++ -std=c++2a -O3 -g0 sendeventmouse.cpp && ./a.out --screen_width=1920 \
--screen_height=1080 \
--x=800 \
--y=800 \
--sleep_time=0 \
--debug=0 \
--device=/dev/input/event5 \
--event_multiply=2 \
--natural_movement=1 \
--use_every_n_element=30 \
--action=0 \
--min_x_variation=-10 \
--max_x_variation=10 \
--min_y_variation=-10 \
--max_y_variation=10 \
&& ./a.out \
--screen_width=1920 \
--screen_height=1080 \
--x=100 \
--y=100 \
--sleep_time=0 \
--debug=0 \
--device=/dev/input/event5 \
--event_multiply=2 \
--natural_movement=1 \
--use_every_n_element=30 \
--action=0
--min_x_variation=-10 \
--max_x_variation=10 \
--min_y_variation=-10 \
--max_y_variation=10

    */

static constexpr std::string_view explanation_on_how_to_use_this_app = R"(

Mandatory arguments:
-------------------
	--screen_width
		Necessary to calculate the correct screen coordinates
	--screen_height
		Necessary to calculate the correct screen coordinates
	--device
		The device to use, must support mouse or swipe events.
        Swipe events are not fully supported yet, because there is a good alternative (input swipe)
		Use ls -l /dev/input/ for a complete list

Optional arguments:
------------------
	--x
		The x coodinate destination of the action
	--y
		The y coodinate destination of the action
	--sleep_time
		The time in microseconds to sleep between each mouse action 
	--debug
		Print debug information, can be used as a "faster sleep", if one microsecond sleep time is too slow
	--event_multiply
		Multiplies the number of events, default is 1 which is very, very fast. The higher the number, the slower the movement
	--natural_movement
		Does a logarithmic movement, it starts fast and gets slower when the destination is close.
	--use_every_n_element
		Use every n element, default is 1, makes the movement faster. Good usage is combined with natural_movement
	--start_x
		The x coodinate start of the action (must be positive)
        If not passed, the current mouse position will be used
	--start_y
		The y coodinate start of the action (must be positive)
        If not passed, the current mouse position will be used
	--action
		0 = moves to --x and --y
		1 = moves to --x and --y and then performs a left click
        2 = moves to --x and --y and then performs a right click
		3 = moves to --x and --y and then performs a middle click   
        4 = left click at current mouse position (visible using getevent -lp)
        5 = right click at current mouse position (visible using getevent -lp)
        6 = middle click at current mouse position (visible using getevent -lp) 
        7 = moves to --x and --y and scrolls down at x and y
		8 = scrolls down at current mouse position (visible using getevent -lp)
		9 = moves to --x and --y and scrolls up at x and y
		10 = scrolls up at current mouse position (visible using getevent -lp)
    --min_x_variation; --max_x_variation; --min_y_variation; --max_y_variation
        To make the mouse/swipe movement more natural (not 100% linear)
        These are not real pixels, but calculated in terms of the linux devices values (usually 32767 or 65535)
    --print_device_info
        Print information about all found devices (useful for debugging)
    --click_duration
		Duration of the click in microseconds
    --sleep_time_before_left_click  
        The time in microseconds to sleep before the left click
	--sleep_time_before_right_click
		The time in microseconds to sleep before the right click
	--sleep_time_before_middle_click
		The time in microseconds to sleep before the middle click
    --sleep_time_before_downscroll
		The time in microseconds to sleep before the downscroll
	--sleep_time_before_upscroll
		The time in microseconds to sleep before the upscroll
    --number_of_scrolls
		The number of scrolls
    --sleep_time_between_scrolls
		The time in microseconds to sleep between each scroll

)";
void static throw_error(const std::string &msg, int exit_code)
{
    std::cerr << On_IRed << msg << Color_Off << '\n';
    std::cerr << IYellow << explanation_on_how_to_use_this_app << Color_Off << '\n';
    exit(exit_code);
}

void static check_if_not_bad_value(const auto v, const auto bad_value, const std::string &error_message)
{
    if (v == bad_value)
    {
        throw_error(error_message, 1);
    }
}

std::ostream &operator<<(std::ostream &os, parsed_args &v)
{
    os << "this_file: " << v.this_file << '\n';
    os << "screen_width: " << v.screen_width << '\n';
    os << "screen_height: " << v.screen_height << '\n';
    os << "x: " << v.x << '\n';
    os << "y: " << v.y << '\n';
    os << "sleep_time: " << v.sleep_time << '\n';
    os << "debug: " << v.debug << '\n';
    os << "device: " << v.device << '\n';
    os << "event_multiply: " << v.event_multiply << '\n';
    os << "natural_movement: " << v.natural_movement << '\n';
    os << "use_every_n_element: " << v.use_every_n_element << '\n';
    os << "action: " << v.action << '\n';
    os << "start_x: " << v.start_x << '\n';
    os << "start_y: " << v.start_y << '\n';
    os << "min_x_variation: " << v.min_x_variation << '\n';
    os << "min_y_variation: " << v.min_y_variation << '\n';
    os << "max_x_variation: " << v.max_x_variation << '\n';
    os << "max_y_variation: " << v.max_y_variation << '\n';
    os << "print_device_info: " << v.print_device_info << '\n';
    os << "click_duration: " << v.click_duration << '\n';
    os << "sleep_time_before_left_click: " << v.sleep_time_before_left_click << '\n';
    os << "sleep_time_before_right_click: " << v.sleep_time_before_right_click << '\n';
    os << "sleep_time_before_middle_click: " << v.sleep_time_before_middle_click << '\n';
    os << "sleep_time_before_downscroll: " << v.sleep_time_before_downscroll << '\n';
    os << "sleep_time_before_upscroll: " << v.sleep_time_before_upscroll << '\n';
    os << "number_of_scrolls: " << v.number_of_scrolls << '\n';
    os << "sleep_time_between_scrolls: " << v.sleep_time_between_scrolls << '\n';
    os << "_screen_width: " << v._screen_width << '\n';
    os << "_screen_height: " << v._screen_height << '\n';
    os << "_x: " << v._x << '\n';
    os << "_y: " << v._y << '\n';
    os << "_sleep_time: " << v._sleep_time << '\n';
    os << "_debug: " << v._debug << '\n';
    os << "_device: " << v._device << '\n';
    os << "_event_multiply: " << v._event_multiply << '\n';
    os << "_natural_movement: " << v._natural_movement << '\n';
    os << "_use_every_n_element: " << v._use_every_n_element << '\n';
    os << "_action: " << v._action << '\n';
    os << "_start_x: " << v._start_x << '\n';
    os << "_start_y: " << v._start_y << '\n';
    os << "_min_x_variation: " << v._min_x_variation << '\n';
    os << "_min_y_variation: " << v._min_y_variation << '\n';
    os << "_max_x_variation: " << v._max_x_variation << '\n';
    os << "_max_y_variation: " << v._max_y_variation << '\n';
    os << "_print_device_info: " << v._print_device_info << '\n';
    os << "_click_duration: " << v._click_duration << '\n';
    os << "_sleep_time_before_left_click: " << v._sleep_time_before_left_click << '\n';
    os << "_sleep_time_before_right_click: " << v._sleep_time_before_right_click << '\n';
    os << "_sleep_time_before_middle_click: " << v._sleep_time_before_middle_click << '\n';
    os << "_sleep_time_before_downscroll: " << v._sleep_time_before_downscroll << '\n';
    os << "_sleep_time_before_upscroll: " << v._sleep_time_before_upscroll << '\n';
    os << "_number_of_scrolls: " << v._number_of_scrolls << '\n';
    os << "_sleep_time_between_scrolls: " << v._sleep_time_between_scrolls << '\n';
    return os;
}

auto static parse_args(int argc, char *argv[])
{
    parsed_args myargs{};
    auto parsed_args_vec{arghelpers::parse_args_to_string_vector(argc, argv)};
    for (auto const &[key, value] : parsed_args_vec)
    {
        // std::cout << key << ": " << value << '\n';
        if (arghelpers::compare2strings(key, "device"))
        {
            myargs.device = value;
            myargs._device = true;
        }
        else if (arghelpers::compare2strings(key, "__FILE__"))
        {
            myargs.this_file = value;
        }
        else if (arghelpers::compare2strings(key, "screen_width"))
        {
            auto screen_width{arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(screen_width, arghelpers::MAX_64BIT_INT, "Invalid screen_width");
            myargs.screen_width = (int)(screen_width);
            myargs._screen_width = true;
        }
        else if (arghelpers::compare2strings(key, "screen_height"))
        {
            auto screen_height{arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(screen_height, arghelpers::MAX_64BIT_INT, "Invalid screen_height");
            myargs.screen_height = (int)(screen_height);
            myargs._screen_height = true;
        }
        else if (arghelpers::compare2strings(key, "x"))
        {
            auto x{arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(x, arghelpers::MAX_64BIT_INT, "Invalid x");
            myargs.x = (int)(x);
            myargs._x = true;
        }
        else if (arghelpers::compare2strings(key, "y"))
        {
            auto y{arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(y, arghelpers::MAX_64BIT_INT, "Invalid y");
            myargs.y = (int)(y);
            myargs._y = true;
        }
        else if (arghelpers::compare2strings(key, "sleep_time"))
        {
            auto sleep_time{arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(sleep_time, arghelpers::MAX_64BIT_INT, "Invalid sleep_time");
            myargs.sleep_time = (uint64_t)sleep_time;
            myargs._sleep_time = true;
        }
        else if (arghelpers::compare2strings(key, "click_duration"))
        {
            auto click_duration{arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(click_duration, arghelpers::MAX_64BIT_INT, "Invalid click_duration");
            myargs.click_duration = (uint64_t)click_duration;
            myargs._click_duration = true;
        }
        else if (arghelpers::compare2strings(key, "debug"))
        {
            auto debug{arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(debug, arghelpers::MAX_64BIT_INT, "Invalid debug");
            myargs.debug = (int)debug;
            myargs._debug = true;
        }
        else if (arghelpers::compare2strings(key, "event_multiply"))
        {
            auto event_multiply{arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(event_multiply, arghelpers::MAX_64BIT_INT, "Invalid event_multiply");
            myargs.event_multiply = (int)event_multiply;
            myargs._event_multiply = true;
        }
        else if (arghelpers::compare2strings(key, "natural_movement"))
        {
            auto natural_movement{arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(natural_movement, arghelpers::MAX_64BIT_INT, "Invalid natural_movement");
            if (natural_movement >= 1)
            {
                myargs.natural_movement = 1;
            }
            myargs._natural_movement = true;
        }
        else if (arghelpers::compare2strings(key, "use_every_n_element"))
        {
            auto use_every_n_element{arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(use_every_n_element, arghelpers::MAX_64BIT_INT, "Invalid use_every_n_element");
            myargs.use_every_n_element = (size_t)use_every_n_element;
            myargs._use_every_n_element = true;
        }
        else if (arghelpers::compare2strings(key, "action"))
        {
            auto action{arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(action, arghelpers::MAX_64BIT_INT, "Invalid action");
            myargs.action = (int)action;
            myargs._action = true;
        }
        else if (arghelpers::compare2strings(key, "start_x"))
        {
            auto start_x{arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(start_x, arghelpers::MAX_64BIT_INT, "Invalid start_x");
            myargs.start_x = (int)start_x;
            myargs._start_x = true;
        }
        else if (arghelpers::compare2strings(key, "start_y"))
        {
            auto start_y{arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(start_y, arghelpers::MAX_64BIT_INT, "Invalid start_y");
            myargs.start_y = (int)start_y;
            myargs._start_y = true;
        }
        else if (arghelpers::compare2strings(key, "min_x_variation"))
        {
            auto min_x_variation{arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(min_x_variation, arghelpers::MAX_64BIT_INT, "Invalid min_x_variation");
            myargs.min_x_variation = (int)min_x_variation;
            myargs._min_x_variation = true;
        }
        else if (arghelpers::compare2strings(key, "max_x_variation"))
        {
            auto max_x_variation{arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(max_x_variation, arghelpers::MAX_64BIT_INT, "Invalid max_x_variation");
            myargs.max_x_variation = (int)max_x_variation;
            myargs._max_x_variation = true;
        }
        else if (arghelpers::compare2strings(key, "min_y_variation"))
        {
            auto min_y_variation{arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(min_y_variation, arghelpers::MAX_64BIT_INT, "Invalid min_y_variation");
            myargs.min_y_variation = (int)min_y_variation;
            myargs._min_y_variation = true;
        }
        else if (arghelpers::compare2strings(key, "max_y_variation"))
        {
            auto max_y_variation{arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(max_y_variation, arghelpers::MAX_64BIT_INT, "Invalid max_y_variation");
            myargs.max_y_variation = (int)max_y_variation;
            myargs._max_y_variation = true;
        }
        else if (arghelpers::compare2strings(key, "print_device_info"))
        {
            auto print_device_info{arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(print_device_info, arghelpers::MAX_64BIT_INT, "Invalid print_device_info");
            myargs.print_device_info = (int)print_device_info;
            myargs._print_device_info = true;
        }
        else if (arghelpers::compare2strings(key, "sleep_time_before_left_click"))
        {
            auto sleep_time_before_left_click{arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(sleep_time_before_left_click, arghelpers::MAX_64BIT_INT,
                                   "Invalid sleep_time_before_left_click");
            myargs.sleep_time_before_left_click = (uint64_t)sleep_time_before_left_click;
            myargs._sleep_time_before_left_click = true;
        }
        else if (arghelpers::compare2strings(key, "sleep_time_before_right_click"))
        {
            auto sleep_time_before_right_click{
                arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(sleep_time_before_right_click, arghelpers::MAX_64BIT_INT,
                                   "Invalid sleep_time_before_right_click");
            myargs.sleep_time_before_right_click = (uint64_t)sleep_time_before_right_click;
            myargs._sleep_time_before_right_click = true;
        }
        else if (arghelpers::compare2strings(key, "sleep_time_before_middle_click"))
        {
            auto sleep_time_before_middle_click{
                arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(sleep_time_before_middle_click, arghelpers::MAX_64BIT_INT,
                                   "Invalid sleep_time_before_middle_click");
            myargs.sleep_time_before_middle_click = (uint64_t)sleep_time_before_middle_click;
            myargs._sleep_time_before_middle_click = true;
        }
        else if (arghelpers::compare2strings(key, "sleep_time_before_downscroll"))
        {
            auto sleep_time_before_downscroll{arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(sleep_time_before_downscroll, arghelpers::MAX_64BIT_INT,
                                   "Invalid sleep_time_before_downscroll");
            myargs.sleep_time_before_downscroll = (uint64_t)sleep_time_before_downscroll;
            myargs._sleep_time_before_downscroll = true;
        }
        else if (arghelpers::compare2strings(key, "sleep_time_before_upscroll"))
        {
            auto sleep_time_before_upscroll{arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(sleep_time_before_upscroll, arghelpers::MAX_64BIT_INT,
                                   "Invalid sleep_time_before_upscroll");
            myargs.sleep_time_before_upscroll = (uint64_t)sleep_time_before_upscroll;
            myargs._sleep_time_before_upscroll = true;
        }
        else if (arghelpers::compare2strings(key, "number_of_scrolls"))
        {
            auto number_of_scrolls{arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(number_of_scrolls, arghelpers::MAX_64BIT_INT, "Invalid number_of_scrolls");
            myargs.number_of_scrolls = (size_t)number_of_scrolls;
            myargs._number_of_scrolls = true;
        }
        else if (arghelpers::compare2strings(key, "sleep_time_between_scrolls"))
        {
            auto sleep_time_between_scrolls{arghelpers::convert_to_int_at_any_cost(value, arghelpers::MAX_64BIT_INT)};
            check_if_not_bad_value(sleep_time_between_scrolls, arghelpers::MAX_64BIT_INT,
                                   "Invalid sleep_time_between_scrolls");
            myargs.sleep_time_between_scrolls = (uint64_t)sleep_time_between_scrolls;
            myargs._sleep_time_between_scrolls = true;
        }
    }

    if (myargs.print_device_info)
    {
        std::cout << myargs;
    }
    if (!myargs._screen_width || !myargs._screen_height || !myargs._device)
    {
        throw_error("Missing arguments", 1);
    }
    if (!myargs._event_multiply)
    {
        myargs.event_multiply = 1;
    }
    if (!myargs._use_every_n_element)
    {
        myargs.use_every_n_element = 1;
    }
    if (!myargs._start_x)
    {
        myargs.start_x = -1;
    }
    if (!myargs._start_y)
    {
        myargs.start_y = -1;
    }
    if (!myargs._number_of_scrolls)
    {
        myargs.number_of_scrolls = 1;
    }
    return myargs;
}

std::vector<std::pair<input_event, uint64_t>> get_downscroll_here_command()
{
    std::vector<std::pair<input_event, uint64_t>> allinputevents;
    allinputevents.reserve(2);
    allinputevents.emplace_back(std::make_pair(input_event{{0, 0}, 2, 8, static_cast<__s32>(0xffffffff)}, 0));
    allinputevents.emplace_back(std::pair<input_event, int64_t>{{{0, 0}, 0, 0, 0}, 0});
    return allinputevents;
}

std::vector<std::pair<input_event, uint64_t>> get_upscroll_here_command()
{
    std::vector<std::pair<input_event, uint64_t>> allinputevents;
    allinputevents.reserve(2);
    allinputevents.emplace_back(std::make_pair(input_event{{0, 0}, 2, 8, 1}, 0));
    allinputevents.emplace_back(std::pair<input_event, int64_t>{{{0, 0}, 0, 0, 0}, 0});
    return allinputevents;
}

std::vector<std::pair<input_event, uint64_t>> get_click_left_here_command(int64_t click_duration)
{
    std::vector<std::pair<input_event, uint64_t>> allinputevents;
    allinputevents.reserve(4);

    allinputevents.emplace_back(std::make_pair(input_event{{0, 0}, 1, 272, 1}, 0));
    allinputevents.emplace_back(std::pair<input_event, int64_t>{{{0, 0}, 0, 0, 0}, click_duration});
    allinputevents.emplace_back(std::make_pair(input_event{{0, 0}, 1, 272, 0}, 0));
    allinputevents.emplace_back(sync_event_no_sleep);
    return allinputevents;
}
std::vector<std::pair<input_event, uint64_t>> get_click_right_here_command(int64_t click_duration)
{
    std::vector<std::pair<input_event, uint64_t>> allinputevents;
    allinputevents.reserve(4);

    allinputevents.emplace_back(std::make_pair(input_event{{0, 0}, 1, 273, 1}, 0));
    allinputevents.emplace_back(std::pair<input_event, int64_t>{{{0, 0}, 0, 0, 0}, click_duration});
    allinputevents.emplace_back(std::make_pair(input_event{{0, 0}, 1, 273, 0}, 0));
    allinputevents.emplace_back(sync_event_no_sleep);
    return allinputevents;
}
std::vector<std::pair<input_event, uint64_t>> get_click_middle_here_command(int64_t click_duration)
{
    std::vector<std::pair<input_event, uint64_t>> allinputevents;
    allinputevents.reserve(4);

    allinputevents.emplace_back(std::make_pair(input_event{{0, 0}, 1, 274, 1}, 0));
    allinputevents.emplace_back(std::pair<input_event, int64_t>{{{0, 0}, 0, 0, 0}, click_duration});
    allinputevents.emplace_back(std::make_pair(input_event{{0, 0}, 1, 274, 0}, 0));
    allinputevents.emplace_back(sync_event_no_sleep);
    return allinputevents;
}
int main(int argc, char *argv[])
{
    parsed_args ar{parse_args(argc, argv)};
    /*

adb -s 127.0.0.1:5560 push sendeventmouse.cpp /sdcard


cp /sdcard/sendeventmouse.cpp . && g++ -std=c++2a -O3 -g0 sendeventmouse.cpp && ./a.out --screen_width=1920 \
--screen_height=1080 \
--x=800 \
--y=800 \
--sleep_time=0 \
--debug=0 \
--device=/dev/input/event5 \
--event_multiply=2 \
--natural_movement=1 \
--use_every_n_element=30 \
--action=0 \
--print_device_info=1 \
&& ./a.out \
--screen_width=1920 \
--screen_height=1080 \
--x=100 \
--y=100 \
--sleep_time=0 \
--debug=0 \
--device=/dev/input/event5 \
--event_multiply=2 \
--natural_movement=1 \
--use_every_n_element=10 \
--action=0 \
--print_device_info=0


cp /sdcard/sendeventmouse.cpp . && g++ -std=c++2a -O3 -g0 sendeventmouse.cpp && ./a.out --screen_width=1920 \
--screen_height=1080 \
--x=800 \
--y=800 \
--sleep_time=0 \
--debug=0 \
--device=/dev/input/event5 \
--event_multiply=2 \
--natural_movement=1 \
--use_every_n_element=30 \
--action=0 \
--start_x=700 \
--start_y=700 \
--min_x_variation=0 \
--max_x_variation=300 \
--min_y_variation=0 \
--max_y_variation=300 \
--print_device_info=1 \
&& ./a.out \
--screen_width=1920 \
--screen_height=1080 \
--x=189 \
--y=268 \
--sleep_time=0 \
--debug=1 \
--device=/dev/input/event5 \
--event_multiply=2 \
--natural_movement=1 \
--use_every_n_element=30 \
--action=1 \
--start_x=100 \
--start_y=100 \
--min_x_variation=0 \
--max_x_variation=300 \
--min_y_variation=0 \
--max_y_variation=300 \
--print_device_info=0 \
--click_duration=1000000 \
--sleep_time_before_left_click=1000000 \
&& ./a.out \
--screen_width=1920 \
--screen_height=1080 \
--debug=1 \
--device=/dev/input/event5 \
--action=4 \
--click_duration=100000 \
--sleep_time_before_left_click=1000000 \
&& ./a.out \
--screen_width=1920 \
--screen_height=1080 \
--debug=1 \
--device=/dev/input/event5 \
--action=5 \
--click_duration=100000 \
--sleep_time_before_left_click=1000000 \
&& ./a.out \
--screen_width=1920 \
--screen_height=1080 \
--debug=1 \
--device=/dev/input/event5 \
--action=6 \
--click_duration=100000 \
--sleep_time_before_left_click=1000000 \
&& ./a.out \
--screen_width=1920 \
--screen_height=1080 \
--debug=1 \
--device=/dev/input/event5 \
--action=8 \
--number_of_scrolls=8 \
--sleep_time_between_scrolls=10000 \
&& ./a.out \
--screen_width=1920 \
--screen_height=1080 \
--debug=1 \
--device=/dev/input/event5 \
--action=10 \
--number_of_scrolls=10 \
--sleep_time_between_scrolls=10000

    */
    argc = 1;
    int c;
    int i;
    int res;
    int pollres;
    int get_time = 1;
    int print_device = 0;
    char _newline = '\n';
    char *newline = &_newline;
    const char *_empty = "";
    uint16_t get_switch = 0;
    struct input_event event;
    int version;
    int print_flags = 0;
    int print_flags_set = 0;
    int dont_block = 0;
    int event_count = 0;
    int sync_rate = 0;
    int64_t last_sync_time = 0;
    const char *device = NULL;
    const char *device_path = "/dev/input";
    print_flags |= PRINT_DEVICE_ERRORS | PRINT_DEVICE | PRINT_DEVICE_NAME | PRINT_POSSIBLE_EVENTS | PRINT_INPUT_PROPS;
    print_flags_set = 1;
    nfds = 1;
    ufds = (struct pollfd *)calloc(1, sizeof(ufds[0]));
    ufds[0].fd = inotify_init();
    ufds[0].events = POLLIN;
    // std::cout << "print flags: " << ufds << '\n';
    res = inotify_add_watch(ufds[0].fd, device_path, IN_DELETE | IN_CREATE);
    if (res < 0)
    {
        fprintf(stderr, "could not add watch for %s, %s\n", device_path, strerror(errno));
        return 1;
    }
    res = scan_dir(device_path, print_flags);
    std::vector<mouselike_devices> valid_mouse_devices;
    valid_mouse_devices.reserve(absmap.size());
    for (auto &[key0, value] : absmap)
    {
        auto device_id{key0};
        std::string device_name{device_mapping[device_id]};
        for (auto &[key1, value2] : value)
        {
            auto event_code{key1};
            int16_t code_x{0};
            int16_t code_y{0};
            // int16_t tmpvaluexy{0};
            int loopcounter = 0;
            for (auto &[key2, value3] : value2)
            {
                if (loopcounter == 0)
                {
                    code_x = key2;
                    code_y = key2;
                }
                else if (loopcounter == 1)
                {
                    if (key2 > code_y)
                    {
                        code_y = key2;
                    }
                    else
                    {
                        code_y = code_x;
                        code_x = key2;
                    }
                }
                loopcounter++;
            }
            int32_t abs_value_x{absmap[device_id][event_code][code_x]};
            int32_t abs_value_y{absmap[device_id][event_code][code_y]};
            int32_t pos_value_x{position_now[device_id][event_code][code_x]};
            int32_t pos_value_y{position_now[device_id][event_code][code_y]};
            uint16_t is_mouse{0};
            uint16_t is_touch{0};
            if (code_x == 53)
            {
                is_touch = 1;
                is_mouse = 0;
            }
            else
            {
                is_mouse = 1;
                is_touch = 0;
            }
            if (event_code == 3)
            {
                valid_mouse_devices.emplace_back(
                    mouselike_devices{device_name, is_mouse, is_touch, (uint16_t)event_code, (uint16_t)code_x,
                                      (uint16_t)code_y, abs_value_x, abs_value_y, pos_value_x, pos_value_y});
            }
        }
    }
    if (ar.print_device_info)
    {
        for (auto &[key0, value] : device_mapping)
        {
            std::cout << key0 << " " << value << std::endl;
        }
        for (const auto &mousevalue : valid_mouse_devices)
        {
            std::cout << mousevalue;
        }
    }
    bool create_move_actions{false};
    if ((ar.action == 0) || (ar.action == 1) || (ar.action == 2) || (ar.action == 3) || (ar.action == 7) ||
        (ar.action == 9))
    {
        create_move_actions = true;
    }
    auto points{get_coords_vector(valid_mouse_devices, ar.device, ar.x, ar.y, ar.screen_width, ar.screen_height,
                                  ar.sleep_time, ar.event_multiply, ar.natural_movement, ar.use_every_n_element,
                                  ar.start_x, ar.start_y, ar.min_x_variation, ar.min_y_variation, ar.max_x_variation,
                                  ar.max_y_variation, ar.choosen_device, ar.choosen_device_index, create_move_actions)};

    if (create_move_actions)
    {
        execute_sendevent(ar.device, points, (bool)ar.debug);
    }
    if (ar.action == 1 || ar.action == 4)
    {
        if (ar._sleep_time_before_left_click && ar.sleep_time_before_left_click != 0)
        {
            sleep_us(ar.sleep_time_before_left_click);
        }
        auto click_here_cmd1{get_click_left_here_command(ar.click_duration)};
        execute_sendevent(ar.device, click_here_cmd1, (bool)ar.debug);
    }
    if (ar.action == 2 || ar.action == 5)
    {
        if (ar._sleep_time_before_right_click && ar.sleep_time_before_right_click != 0)
        {
            sleep_us(ar.sleep_time_before_right_click);
        }
        auto click_here_cmd2{get_click_right_here_command(ar.click_duration)};
        execute_sendevent(ar.device, click_here_cmd2, (bool)ar.debug);
    }
    if (ar.action == 3 || ar.action == 6)
    {
        if (ar._sleep_time_before_middle_click && ar.sleep_time_before_middle_click != 0)
        {
            sleep_us(ar.sleep_time_before_middle_click);
        }
        auto click_here_cmd3{get_click_middle_here_command(ar.click_duration)};
        execute_sendevent(ar.device, click_here_cmd3, (bool)ar.debug);
    }
    if (ar.action == 7 || ar.action == 8)
    {
        if (ar._sleep_time_before_downscroll && ar.sleep_time_before_downscroll != 0)
        {
            sleep_us(ar.sleep_time_before_downscroll);
        }
        auto click_here_cmd4{get_downscroll_here_command()};
        for (size_t i{}; i < ar.number_of_scrolls; i++)
        {
            execute_sendevent(ar.device, click_here_cmd4, (bool)ar.debug);
            if (ar._sleep_time_between_scrolls && ar.sleep_time_between_scrolls != 0)
            {
                sleep_us(ar.sleep_time_between_scrolls);
            }
        }
    }
    if (ar.action == 9 || ar.action == 10)
    {
        if (ar._sleep_time_before_upscroll && ar.sleep_time_before_upscroll != 0)
        {
            sleep_us(ar.sleep_time_before_upscroll);
        }
        auto click_here_cmd5{get_upscroll_here_command()};
        for (size_t i{}; i < ar.number_of_scrolls; i++)
        {
            execute_sendevent(ar.device, click_here_cmd5, (bool)ar.debug);
            if (ar._sleep_time_between_scrolls && ar.sleep_time_between_scrolls != 0)
            {
                sleep_us(ar.sleep_time_between_scrolls);
            }
        }
    }
    return 0;
}
