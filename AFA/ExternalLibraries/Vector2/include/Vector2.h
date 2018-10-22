///<summary>
/// Vector2f is a template class. 
/// Its use is to handle two variables
/// of type T in the form of coordinate
/// geometry. The ideal variable types
/// are int, float and double. They're
/// types are defined as Vector2fi/f/d.
///</summary>
///<Date>
/// 05/10/2018
///</Date>
///<author>
/// Jack Keogh.
///</author>


namespace jk
{
	struct Vector2f
	{
		// variables
		float x;
		float y;

		/// <summary>
		/// Default constructor
		/// 
		/// Initialises x and y variables to 0.
		/// </summary>
		Vector2f() :
			x(0), y(0) {};

		/// <summary>
		/// Overload constructor
		/// 
		/// Initialises x and y to parameters
		/// passed in.
		/// </summary>
		/// <param name="vx">Overload value for x.</param>
		/// <param name="vy">Overload value for y.</param>
		Vector2f(float vx, float vy) :
			x(vx), y(vy) {};

		/// <summary>
		/// Overload constructor
		/// 
		/// Initialises x and y to parameters
		/// of Vector2f passed in.
		/// </summary>
		/// <param name="v">Vector2f to overload x and y with.</param>
		Vector2f(const Vector2f& v) :
			x(v.x), y(v.y) {};

		/// <summary>
		/// Equals operator
		/// 
		/// Assigns x and y variables to param's
		/// x and y variables.
		/// </summary>
		/// <param name="v">Vector2f parameter.</param>
		/// <returns>This Vector2f Object.</returns>
		Vector2f& operator=(const Vector2f& v)
		{
			x = v.x;
			y = v.y;
			return *this;
		}

		/// <summary>
		/// Addition operator
		/// 
		/// Adds two vectors together and returns
		/// the result as a Vector2f.
		/// </summary>
		/// <param name="r">Vector2f to be added.</param>
		/// <returns>A Vector2f object.</returns>
		Vector2f operator+(const Vector2f& r) const
		{
			return Vector2f(x + r.x, y + r.y);
		}

		/// <summary>
		/// Subtract operator
		/// 
		/// Subtracts two vectors and returns
		/// the result as a Vector2f.
		/// </summary>
		/// <param name="r">Vector2f to be subtracted.</param>
		/// <returns>A Vector2f object.</returns>
		Vector2f operator-(const Vector2f& r)
		{
			return Vector2f(x - r.x, y - r.y);
		}

		/// <summary>
		/// Division operator
		/// 
		/// Divides the left vector by the right vector
		/// and returns the result as a Vector2f object.
		/// </summary>
		/// <param name="r">Vector2f to use to divide by.</param>
		/// <returns>A Vector2f object.</returns>
		Vector2f operator/(const Vector2f& r)
		{
			return Vector2f(x / r.x, y / r.y);
		}

		/// <summary>
		/// Multiplyer operator
		/// 
		/// Multiples the left vector by the right vector
		/// and returns the result as a Vector2f object.
		/// </summary>
		/// <param name="r">Vector2f to multiply by.</param>
		/// <returns>A Vector2f object.</returns>
		Vector2f operator*(const Vector2f& r)
		{
			return Vector2f(x * r.x, y * r.y);
		}

		/// <summary>
		/// Scalar operator
		/// 
		/// Multiplies the left vector by right floating point number
		/// and returns the result as a Vector2f object.
		/// </summary>
		/// <param name="r">Floating point number to multiply by.</param>
		/// <returns>A Vector2f object.</returns>
		Vector2f operator*(const float r)
		{
			return Vector2f(x * r, y * r);
		}

		/// <summary>
		/// Add and Assign operator
		/// 
		/// Adds the right Vector2f to the left Vector2f
		/// and returns the left Vector2f object.
		/// </summary>
		/// <param name="r">Vector2f to add by.</param>
		/// <returns>This Vector2f Object.</returns>
		Vector2f& operator+=(const Vector2f& r)
		{
			x += r.x;
			y += r.y;

			return *this;
		}

		/// <summary>
		/// Subtract and Assign operator
		/// 
		/// Subtracts the right Vector2f from the left 
		/// Vector2f and returns the left Vector2f object.
		/// </summary>
		/// <param name="r">Vector2f to subtract by.</param>
		/// <returns>This Vector2f Object.</returns>
		Vector2f& operator-=(const Vector2f& r)
		{
			x -= r.x;
			y -= r.y;

			return *this;
		}

		/// <summary>
		/// Divide and Assign operator
		/// 
		/// Divides the right Vector2f from the left Vector2f
		/// and returns the left Vector2f object.
		/// </summary>
		/// <param name="r">Vector2f to divide by.</param>
		/// <returns>This Vector2f Object.</returns>
		Vector2f& operator/=(const Vector2f& r)
		{
			x /= r.x;
			y /= r.y;

			return *this;
		}

		/// <summary>
		/// Multiply and Assign operator
		/// 
		/// Multiplies the left Vector2f by the right Vector2f
		/// and returns the left Vector2f object.
		/// </summary>
		/// <param name="r">Vector2f to multiply by.</param>
		/// <returns>This Vector2f Object.</returns>
		Vector2f& operator*=(const Vector2f& r)
		{
			x *= r.x;
			y *= r.y;

			return *this;
		}

		/// <summary>
		/// Scalar operator
		/// 
		/// Multiplies the left vector by the right floating point number
		/// and returns the left Vector2f object.
		/// </summary>
		/// <param name="r">Floating point number to multiply by.</param>
		/// <returns>A Vector2f object.</returns>
		Vector2f& operator*=(const float r)
		{
			x *= r;
			y *= r;

			return *this;
		}

		/// <summary>
		/// Equate operator
		/// 
		/// Checks if the left vector equals the right vector.
		/// </summary>
		/// <param name="r">Vector2f to compare.</param>
		/// <returns>A True or False Statement.</returns>
		bool operator==(const Vector2f& r)
		{
			if (x == r.x && y == r.y)
				return true;
			else
				return false;
		}

		/// <summary>
		/// Inequate operator
		/// 
		/// Checks if the left vector does not equal the right vector.
		/// </summary>
		/// <param name="r">Vector2f to compare.</param>
		/// <returns>A True or False Statement.</returns>
		bool operator!=(const Vector2f& r)
		{
			return !(*this == r);
		}

		/// <summary>
		/// Normalises the Vector2f object.
		/// </summary>
		/// <returns>A normalised Vector2f Object.</returns>
		Vector2f& Normalise();

		/// <summary>
		/// Returns the size of the vector.
		/// </summary>
		/// <returns>A floating point value.</returns>
		float Magnitude();
	};
}