#pragma once
// C++ 17
#include <string_view>
template <class T>
constexpr std::string_view type_name()
{
	using namespace std;
#ifdef __clang__
	string_view p = __PRETTY_FUNCTION__;
	return string_view(p.data() + 34, p.size() - 34 - 1);
#elif defined(__GNUC__)
	string_view p = __PRETTY_FUNCTION__;
#  if __cplusplus < 201402
	return string_view(p.data() + 36, p.size() - 36 - 1);
#  else
	return string_view(p.data() + 49, p.find(';', 49) - 49);
#  endif
#elif defined(_MSC_VER)
	string_view p = __FUNCSIG__;
	return string_view(p.data() + 84, p.size() - 84 - 7);
#endif
}

// End C++ 17
/*
#include <type_traits>
#include <typeinfo>
#ifndef _MSC_VER
#   include <cxxabi.h>
#endif
#include <memory>
#include <string>
#include <cstdlib>

template <class T>
std::string
type_name()
{
typedef typename std::remove_reference<T>::type TR;
std::unique_ptr<char, void(*)(void*)> own
(
#ifndef _MSC_VER
abi::__cxa_demangle(typeid(TR).name(), nullptr,
nullptr, nullptr),
#else
nullptr,
#endif
std::free
);
std::string r = own != nullptr ? own.get() : typeid(TR).name();
if (std::is_const<TR>::value)
r += " const";
if (std::is_volatile<TR>::value)
r += " volatile";
if (std::is_lvalue_reference<T>::value)
r += "&";
else if (std::is_rvalue_reference<T>::value)
r += "&&";
return r;
}
*/