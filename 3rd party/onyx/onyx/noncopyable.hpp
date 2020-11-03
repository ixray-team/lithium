#pragma once

namespace onyx
{
	class noncopyable 
	{
	public:
		noncopyable() = default;
		~noncopyable() = default;

	private:
		noncopyable(const noncopyable&) = delete;
		noncopyable& operator=(const noncopyable&) = delete;
	};
}