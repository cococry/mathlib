#pragma once

#include <initializer_list>
#include <stdlib.h>

#include "core.h"

namespace mtlb {
	class vec {
	public:
		/// <summary>
		/// Defines a vector in any possible interpretation. In it's core, a vector in this
		/// library is defined by a dimension ( or the amount of elements, the vector can hold )
		/// and a set of values. A vector can have any number of dimension and any possible values.
		/// This class is a hybrid class of member functions and static utility functions. For most
		/// of the member functions in the class, there is also a static function. So this class can 
		/// act as a namespace for general vector utility and for instantiating a vector with and 
		/// calling functions on it.<para/>
		/// INFO: To allocate a vector DONT use this constructor. This construct does not initialize anything.
		/// Use the std::initializer_list(float) constructor instead.
		/// </summary>
		vec() {
			values = nullptr;
			dimension = 0;
		}


		/// <summary>
		/// This constructor allocates space for all of the specified values 
		/// in the initializer list. Those are then appended in order to the "values" 
		/// member variable, in which the values of the vector are stored. 
		/// </summary>
		/// <param name="vals">Defines all values within the vector</param>
		vec(const std::initializer_list<float>& vals);


		/// <summary>
		///	Creates a vector with N values where N = paramater "dimension".
		/// All of the elements are equal to the "val" parameter.
		/// </summary>
		/// <param name="dimension">Specifies the dimension of the vector</param>
		/// <param name="val">The value of all elments of the vector </param>
		static vec uniform(size_t dimension, float val);


		/// <summary>
		/// Allocates space for a N number of float values where N is the "dimension
		/// parameter. The "dimension" member variable of this class is being set to
		/// the given "dimension" parameter.
		/// </summary>
		/// <param name="dimension">Specifies the dimension of the vector</param>
		static vec allocate(size_t dimension);


		/// <summary>
		/// Returns a vector whose values are all of paramerter "v"'s values multiplied by
		/// the given "scaler" parameter.
		/// </summary>
		/// <param name="v">Specifies the vector to which the scaler should be mutliplied</param>
		/// <param name="scaler">Scaler to multiply</param>
		static vec scalerMultipliaction(const vec& v, float scaler);


		/// <summary>
		/// Returns a vector whose values are all of paramerter "v"'s values divided by
		/// the given "scaler" parameter.
		/// </summary>
		/// <param name="v">Specifies the vector to which the scaler should be divided</param>
		/// <param name="scaler">Scaler to be divide</param>
		static vec scalerDivision(const vec& v, float scaler);


		/// <summary>
		/// Adds a scaler value (parameter "scaler") to all of the elements of parameter "v" 
		/// and returns the resulting vector.
		/// </summary>
		/// <param name="v">Specifies the vector to which the scaler should be divided</param>
		/// <param name="scaler">Scaler to be divide</param>
		static vec scalerAddition(const vec& v, float scaler);


		/// <summary>
		/// Substracts a scaler value (parameter "scaler") from all of the elements of parameter "v" 
		/// and returns the resulting vector.
		/// </summary>
		/// <param name="v">Specifies the vector to which the scaler should be divided</param>
		/// <param name="scaler">Scaler to be divide</param>
		static vec scalerSubstraction(const vec& v, float scaler);


		/// <summary>
		/// Returns if all of the indivual elements of two vectors ("v1" parameter and "v2" parameter) are the same AND in order.
		/// </summary>
		static bool compare(const vec& v1, const vec& v2);


		/// <summary>
		/// Prints all elements of a given vector in a certain layout. Example: { 6.9, 3.1, 1.9 }
		/// This uses the C++ way of printing to the console ( std::cout ) as ostream.
		/// </summary>
		/// <param name="v">Specifies the vector of which its elements are being printed</param>
		static void print(const vec& v);


		/// <summary>
		/// Adds all elements of two given vectors ( parameter "v1" & parameter "v2" ) and returns the resulting vector.
		/// </summary>
		/// <param name="v1">Specifies the first vector for the equation</param>
		/// <param name="v2">Specifies the second vector for the equation</param>
		/// <returns></returns>
		static vec add(const vec& v1, const vec& v2);


		/// <summary>
		/// Substracts a given vector ( parameter "v1" ) from another ( parameter "v2" ) and returns the resulting vector. 
		/// </summary>
		/// <param name="v1">Specifies the first vector for the equation</param>
		/// <param name="v2">Specifies the second vector for the equation</param>
		/// <returns></returns>
		static vec substract(const vec& v1, const vec& v2);


		/// <summary>
		/// Multiplies two given vectors ( parameter "v1" & parameter "v2" ) together and returns the resulting vector. 
		/// </summary>
		/// <param name="v1">Specifies the first vector for the equation</param>
		/// <param name="v2">Specifies the second vector for the equation</param>
		/// <returns></returns>
		static vec multiply(const vec& v1, const vec& v2);


		/// <summary>
		/// Divides a given vector ( parameter "v1" )from another ( parameter "v2" ) and returns the resulting vector. 
		/// </summary>
		/// <param name="v1">Specifies the first vector for the equation</param>
		/// <param name="v2">Specifies the second vector for the equation</param>
		/// <returns></returns>
		static vec divide(const vec& v1, const vec& v2);


		/// <summary>
		/// Returns the dot product of two given vectors ( parameter "v1" & parameter "v2" ).
		/// </summary>
		/// <param name="v1">Specifies the first vector for the dot product</param>
		/// <param name="v2">Specifies the second vector for the dot product</param>
		static float dot(const vec& v1, const vec& v2);


		/// <summary>
		/// Calculates the cross product of two given vectors ( parameter "v1" & parameter "v2" )
		/// and returns the resulting vector.
		/// </summary>
		/// <param name="v1">Specifies the first vector for the cross product</param>
		/// <param name="v2">Specifies the second vector for the cross product</param>
		/// <returns></returns>
		static vec cross(const vec& v1, const vec& v2);


		/// <summary>
		/// Returns if two given vectors ( parameter "v1" & parameter "v2" ) are perpendicular.
		/// This is calculated by taking the dot product of both vectors and
		/// checking if it returns 0.
		/// </summary>
		/// <param name="v1"></param>
		/// <param name="v2"></param>
		/// <returns></returns>
		static bool orthogonal(const vec& v1, const vec& v2);


		/// <summary>
		/// Returns a number that contains every value of the given vector ( parameter "v" )
		/// squared. The square root of this value defines the magnitude of the vector. 
		/// To get the magnitude of a vector use vec::magnitudeOf() or vec.magnitude().
		/// </summary>
		/// <param name="v1">Specifies the vector for the calculation</param>
		static float squaredMagnitudeOf(const vec& v);


		/// <summary>
		/// Returns the magnitude ( or length ) of given vector ( parameter "v").
		/// </summary>
		/// <param name="v">Specifies the vector for the calculation</param>
		/// <returns></returns>
		static float magnitudeOf(const vec& v);


		/// <summary>
		/// Divides each element of a given vector ( parameter "v" ) by its magnitude.
		/// This returns a vector with magnitude one and the direction in which the
		/// given vector "v" was pointing in. This vector is also called a direction
		/// vector.
		/// </summary>
		/// <param name="v">Specifies the vector to get the normalized version froms</param>
		/// <returns></returns>
		static vec normalized(const vec& v);


		/// <summary>
		/// This member function returns if all of the values of this instance of the class are identical to 
		/// all of the values from "v" (parameter) AND in the same order.
		/// </summary>
		/// <param name="v">Specifies the vector with which to compare</param>
		/// <returns></returns>
		bool compareWith(const vec& v);


		/// <summary>
		/// This member function multiplies all elements of the vector of this instance by the
		/// given scaler ("v" parameter)
		/// </summary>
		/// <param name="scaler">Scaler to multiply</param>
		void multiplyByScaler(float scaler);


		/// <summary>
		/// This member function divides all elements of the vector of this instance 
		/// by the given scaler ("v" parameter)
		/// </summary>
		/// <param name="scaler">Scaler to divide</param>
		void divideByScaler(float scaler);


		/// <summary>
		/// This member function adds the given scaler ("v" parameter) to the
		/// vector of this instance.
		/// </summary>
		/// <param name="scaler">Scaler to divide</param>
		void addScaler(float scaler);


		/// <summary>
		/// This member function substracts the given scaler ("v" parameter) from the
		/// vector of this instance.
		/// </summary>
		/// <param name="scaler">Scaler to divide</param>
		void substractScaler(float scaler);


		/// <summary>
		/// This member function adds a vector to the vector of this instance.
		/// </summary>
		/// <param name="v">Vector for adding to</param>
		void addVector(const vec& v);


		/// <summary>
		/// This member function substracts a vector from the vector of this instance.
		/// </summary>
		/// <param name="v">Vector for substracting from</param>
		void substractVector(const vec& v);


		/// <summary>
		/// This member function multiplies a vector with the vector of this instance.
		/// </summary>
		/// <param name="v">Vector for substracting from</param>
		void multiplyWithVector(const vec& v);


		/// <summary>
		/// This member function divides a vector with
		///  the vector of this instance.
		/// </summary>
		/// <param name="v">Vector for substracting from</param>
		void divideByVector(const vec& v);


		/// <summary>
		/// This member function returns if the vector of this instance is perpendicular to a given
		/// vector (parameter "v"). This is calculated by taking the dot product of both vectors and
		/// checking if it returns 0.
		/// </summary>
		/// <param name="v"></param>
		bool orthogonalWith(const vec& v);


		/// <summary>
		/// This member function returns a value which contains all of the values in the vector of this instance
		/// squared. The square root of this value defines the magnitude of this vector. To get the magnitude of
		/// a vector use vec::magnitudeOf(v) or vec.magnitude().
		/// </summary>
		float squaredMagnitude();


		/// <summary>
		/// This member function returns the magnitude ( or length ) of the vector of this instance.
		/// </summary>
		float magnitude();


		void normalize();

		/// <summary>
		/// This member function gets the raw pointer of values in this instance of the class
		/// </summary>
		/// <returns>Private variable "values"</returns>
		inline float* getValues() const {
			return values;
		}


		/// <summary>
		/// This member function gets the dimension of the vector
		/// </summary>
		/// <returns>Private variable "dimension"</returns>
		inline size_t getDimension() const {
			return dimension;
		}
	private:
		float* values;
		size_t dimension;
	};
}