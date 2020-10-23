#pragma once
#include <libraries\std.hpp>
#include <libraries\sfml.hpp>
#include <libraries\lua.hpp>
#include <libraries/gui.hpp>

namespace cap
{
	// ������������ ������ ��� LuaRef
	class LuaMap
	{
	private:
		LuaRef* m_values;
		string* m_keys;
		size_t m_count;

	public:
		LuaMap();

		int find(string key);
		void set(string key, LuaRef values);
		LuaRef get(string key);
	};

	// ��������� ������
	class Point
	{
	public:
		double x, y;

		Point(double x = 0.0, double y = 0.0);
		Point(const Vector2f& point);
		Point(const Vector2i& point);
		Point(const Vector2u& point);

		inline Point round()
		{
			return Point((int)x, (int)y);
		}

		friend Point operator+ (const Point& left, const Point& right);
		friend Point operator- (const Point& left, const Point& right);
		friend Point operator* (const Point& left, const Point& right);
		friend Point operator* (const Point& left, float right);
		friend Point operator/ (const Point& left, const Point& right);
		friend Point operator/ (const Point& left, float right);

		operator Vector2f();
		operator Vector2i();
		operator Vector2u();
		operator ImVec2();

		operator const char* ();
	};

	// �������������
	class Rect
	{
	public:
		double x, y, width, height;

		Rect(double x = 0.0, double y = 0.0, double h = 0.0, double w = 0.0);
		Rect(Point pos , Point size);

		Point getPosition();
		Point getSize();

		operator IntRect();
		operator FloatRect();

	};

	// ������ ��������
	class Texture
	{
	private:
		sf::Image* m_image;
		sf::Texture* m_texture;

	public:
		Texture();

		Sprite toSprite();
		Sprite cutRect(Rect rect);

		operator sf::Texture();
		operator sf::Image();

	};

	// �������� 
	class Animation : public Drawable
	{
		using Frame = pair<int, const Sprite>;

	private:
		bool started = false;
		int current_frame = 0;
		vector<Frame> frames;

	public:
		Animation() = default;

		void addFrame(int delay, const Sprite texture);

		void setCurentFrame(int frame);
		
	};
}