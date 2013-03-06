/*
 * KdNode.hpp
 *
 *  Created on: 17.01.2013
 *      Author: Dominik Feldschnieders
 */

#ifndef KDNODE_HPP_
#define KDNODE_HPP_

#include "geometry/Vertex.hpp"
#include "io/Model.hpp"
#include "io/DataStruct.hpp"
#include "geometry/Vertex.hpp"


/**
 * @brief A class to the representation of a sheet in a search tree.
 */
namespace lssr{
template<typename VertexT>
class KdNode {
public:
	/**
	 * @brief Construktor
	 *
	 * @param points IndexBuffer of the pointcloud
	 * @param min This vector represents the "bottom" of the scene (minimum x, y and z value)
	 * @param max This vector represents the "top" of the scene (maximum x, y and z value)
	 */
	KdNode(coord3fArr points, VertexT min, VertexT max);


	/**
	 * @brief Destruktor
	 */
	virtual ~KdNode();

	/**
	 * @brief Gives back the number of points contained in the node.
	 */
	double getnumpoints();

	/**
	 * @brief Set the number of points contained in the node.
	 *
	 * @param num Value to be set.
	 */
	void setnumpoints(double num);

	boost::shared_array<size_t> getIndizes();

	void setIndizes(boost::shared_array<size_t> indi);

	/**
	 * @brief Get the node points
	 */
	coord3fArr getPoints();

	// IndexBuffer of the pointcloud
	coord3fArr node_points;

	// number of points contained in the node.
	double m_numpoints;

	boost::shared_array<size_t> indizes;
	// This vector represents the "bottom" of the scene (minimum x, y and z value)
	VertexT m_maxvertex;
	//This vector represents the "top" of the scene (maximum x, y and z value)
	VertexT m_minvertex;

};
}
#include "KdNode.tcc"
#endif /* KDNODE_HPP_ */
