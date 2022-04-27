#include "..\include\mathlib\vec.h"

#include <iostream>
#include <assert.h>
#include <math.h>

namespace mtlb {
	vec::vec(const std::initializer_list<float>& vals) {
		values = (float*)malloc(vals.size() * sizeof(float));
		dimension = vals.size();

		u32 i = 0;
		for (auto& val : vals) {
			values[i] = val;
			i++;
		}
	}

	vec vec::uniform(size_t dimension, float val) {
		vec ret = allocate(dimension);

		for (i32 i = 0; i < dimension; i++) {
			ret.values[i] = val;
		}
		return ret;
	}
	vec vec::allocate(size_t dimension) {
		vec ret;

		ret.dimension = dimension;
		ret.values = (float*)malloc(dimension * sizeof(float));

		return ret;
	}
	bool vec::compare(const vec& v1, const vec& v2) {
		assert(v1.dimension == v2.dimension);
		bool identical = true;

		for (i32 i = 0; i < v1.dimension; i++) {
			if (v1.values[i] != v2.values[i]) {
				identical = false;
			}
		}
		return identical;
	}
	void vec::print(const vec& v) {
		std::cout << "{ ";
		for (i32 i = 0; i < v.dimension; i++) {
			std::cout << v.getValues()[i];
			if (i < v.dimension - 1) {
				std::cout << ", ";
			}
		}
		std::cout << " }\n";
	}
	vec vec::add(const vec& v1, const vec& v2) {
		assert(v1.dimension == v2.dimension);
		vec ret = allocate(v1.dimension);

		for (i32 i = 0; i < v1.dimension; i++) {
			ret.values[i] = v1.values[i] + v2.values[i];
		}
		return ret;
	}
	vec vec::substract(const vec& v1, const vec& v2) {
		assert(v1.dimension == v2.dimension);

		vec ret = allocate(v1.dimension);

		for (i32 i = 0; i < v1.dimension; i++) {
			ret.values[i] = v1.values[i] - v2.values[i];
		}
		return ret;
	}
	vec vec::multiply(const vec& v1, const vec& v2) {
		assert(v1.dimension == v2.dimension);

		vec ret = allocate(v1.dimension);

		for (i32 i = 0; i < v1.dimension; i++) {
			ret.values[i] = v1.values[i] * v2.values[i];
		}
		return ret;
	}
	vec vec::divide(const vec& v1, const vec& v2) {
		assert(v1.dimension == v2.dimension);

		vec ret = allocate(v1.dimension);
		for (i32 i = 0; i < v1.dimension; i++) {
			ret.values[i] = v1.values[i] / v2.values[i];
		}
		return ret;
	}
	float vec::dot(const vec& v1, const vec& v2) {
		float ret = 0.0f;
		if (v1.dimension == v2.dimension) {
			for (i32 i = 0; i < v1.dimension; i++) {
				ret += v1.values[i] * v2.values[i];
			}
		}
		return ret;
	}
	vec vec::cross(const vec& v1, const vec& v2) {
		assert(v1.dimension == v2.dimension);

		vec ret = allocate(3);

		ret.values[0] =
			(v1.values[1] * v2.values[2]) - (v1.values[2] * v2.values[1]);
		ret.values[1] = -1 * ((v1.values[0] * v2.values[2]) -
			(v1.values[2] * v2.values[0]));
		ret.values[2] =
			(v1.values[0] * v2.values[1]) - (v1.values[1] * v2.values[0]);

		return ret;
	}
	bool vec::orthogonal(const vec& v1, const vec& v2) {
		return v1.dimension == v2.dimension ? dot(v1, v2) : false;
	}
	float vec::squaredMagnitudeOf(const vec& v) {
		float ret = 0.0f;

		for (i32 i = 0; i < v.dimension; i++) {
			ret += v.values[i] * v.values[i];
		}
		return ret;
	}
	float vec::magnitudeOf(const vec& v)
	{
		return sqrt(squaredMagnitudeOf(v));
	}
	vec vec::scalerMultipliaction(const vec& v, float scaler) {
		vec ret = v;
		for (i32 i = 0; i < v.dimension; i++) {
			ret.values[i] *= scaler;
		}
		return ret;
	}
	vec vec::scalerDivision(const vec& v, float scaler) {
		vec ret = v;
		for (i32 i = 0; i < v.dimension; i++) {
			ret.values[i] /= scaler;
		}
		return ret;
	}
	vec vec::scalerAddition(const vec& v, float scaler) {
		vec ret = v;
		for (i32 i = 0; i < v.dimension; i++) {
			ret.values[i] += scaler;
		}
		return ret;
	}
	vec vec::scalerSubstraction(const vec& v, float scaler) {
		vec ret = v;
		for (i32 i = 0; i < v.dimension; i++) {
			ret.values[i] += scaler;
		}
		return ret;
	}
	vec vec::normalized(const vec& v) {
		vec ret = allocate(v.dimension);
		float magnitude = magnitudeOf(v);

		for (i32 i = 0; i < v.dimension; i++) {
			ret.values[i] = v.values[i] / magnitude;
		}
		return ret;
	}
	bool vec::compareWith(const vec& v) {
		assert(v.dimension == this->dimension);
		bool identical = true;

		for (i32 i = 0; i < this->dimension; i++) {
			if (v.values[i] != this->values[i]) {
				identical = false;
			}
		}
		return identical;
	}
	void vec::multiplyByScaler(float scaler) {
		for (i32 i = 0; i < this->dimension; i++) {
			this->values[i] *= scaler;
		}
	}
	void vec::divideByScaler(float scaler) {
		for (i32 i = 0; i < this->dimension; i++) {
			this->values[i] /= scaler;
		}
	}
	void vec::addScaler(float scaler)
	{
		for (i32 i = 0; i < this->dimension; i++) {
			this->values[i] += scaler;
		}
	}
	void vec::substractScaler(float scaler)
	{
		for (i32 i = 0; i < this->dimension; i++) {
			this->values[i] -= scaler;
		}
	}
	void vec::addVector(const vec& v) {
		assert(v.dimension == this->dimension);
		for (i32 i = 0; i < this->dimension; i++) {
			this->values[i] += v.values[i];
		}
	}
	void vec::substractVector(const vec& v) {
		assert(v.dimension == this->dimension);
		for (i32 i = 0; i < this->dimension; i++) {
			this->values[i] -= v.values[i];
		}
	}
	void vec::multiplyWithVector(const vec& v) {
		assert(v.dimension == this->dimension);
		for (i32 i = 0; i < this->dimension; i++) {
			this->values[i] *= v.values[i];
		}
	}
	void vec::divideByVector(const vec& v) {
		assert(v.dimension == this->dimension);
		for (i32 i = 0; i < this->dimension; i++) {
			this->values[i] /= v.values[i];
		}
	}
	bool vec::orthogonalWith(const vec& v) {
		return this->dimension == v.dimension ? dot(*this, v) : false;
	}
	float vec::squaredMagnitude()
	{
		float ret = 0.0f;

		for (i32 i = 0; i < this->dimension; i++) {
			ret += this->values[i] * this->values[i];
		}
		return ret;
	}
	float vec::magnitude()
	{
		return sqrt(this->squaredMagnitude());
	}
	void vec::normalize()
	{
		vec norm_vec = normalized(*this);

		for (i32 i = 0; i < this->dimension; i++) {
			this->values[i] = norm_vec.values[i];
		}
	}
}

