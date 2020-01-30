#pragma once

/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

#include "math/ga_vec3f.h"
#include "math/ga_vec4f.h"

/*
** Floating point 4x4 matrix.
*/
struct ga_mat4f
{
	float data[4][4];

	/*
	** Build an identity matrix.
	*/
	void make_identity();

	/*
	** Build a translation matrix.
	*/
	void make_translation(const ga_vec3f& __restrict t);

	/*
	** Build a uniform scaling matrix.
	*/
	void make_scaling(float s);

	/*
	** Build a counter-clockwise rotation about X matrix.
	*/
	void make_rotation_x(float angle);

	/*
	** Build a counter-clockwise rotation about X matrix.
	*/
	void make_rotation_y(float angle);

	/*
	** Build a counter-clockwise rotation about X matrix.
	*/
	void make_rotation_z(float angle);

	/*
	** Apply translation to the given matrix.
	*/
	void translate(const ga_vec3f& __restrict t);

	/*
	** Apply uniform scaling to the given matrix.
	*/
	void scale(float s);

	/*
	** Apply counter-clockwise rotation about X to the given matrix.
	*/
	void rotate_x(float angle);

	/*
	** Apply counter-clockwise rotation about Y to the given matrix.
	*/
	void rotate_y(float angle);

	/*
	** Apply counter-clockwiser cotation about Z to the given matrix.
	*/
	void rotate_z(float angle);

	/*
	** Multiply two matrices and store the result in a third.
	*/
	ga_mat4f operator*(const ga_mat4f& __restrict b) const;

	/*
	** Multiply a matrix by another, storing the result in the first.
	*/
	ga_mat4f& operator*=(const ga_mat4f& __restrict m);

	/*
	** Transform a vector by a matrix.
	*/
	ga_vec4f transform(const ga_vec4f& __restrict in) const;

	/*
	** Transforms a vector by a matrix.
	** 
	** This method is similar to transform_point but it ignores 
	** translation as translating a vector is nonsensical.
	*/
	ga_vec3f transform_vector(const ga_vec3f& __restrict in) const;

	/*
	** Transforms a point by a matrix.
	*/
	ga_vec3f transform_point(const ga_vec3f& __restrict in) const;

	/*
	** Transpose a matrix.
	*/
	void transpose();

	/*
	** Determine if two matrices are largely equivalent.
	*/
	bool equal(const ga_mat4f& __restrict b);
};
