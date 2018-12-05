#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/highgui.hpp>      //for imshow
#include <vector>
#include <iostream>


#include "Map.hpp"
#include "MapTree.hpp"
#include "utils.h"

#define IMG_MAP_PATH "robmob_map_simu.png"	// hard
//#define IMG_MAP_PATH "robmob_map_simu2.png" //easy
#define NAME_MAP_WIN "Map window"


int main(int argc, char **argv)
{
	/********************************************** ONE SHOT PROCEDURE  **********************************************/
	
	Map mapSim(IMG_MAP_PATH, NAME_MAP_WIN);
	MapTree mapTree(mapSim);
	
	//Pos src(100,100), dest(400,400); // test fort easy map
	Pos src(80,80), dest(300,300); // test fort hard map
	
	mapSim.drawMapSrcDest(src, dest);
	
	// Compute :
	std::vector<Pos> sp = mapTree.computeShorestPath(src, dest);
	
	// Display res :
	//mapSim.drawMapGraphPath(mapTree.getVertices(), mapTree.getGraph(), sp); // with the graph
	mapSim.drawMapShortestPath(sp); // withou the graph
	
	
	/******************************************** STEP BY STEP PROCEDURE  ********************************************/
/*
	// Map display
	Map mapSim(IMG_MAP_PATH, NAME_MAP_WIN);
	mapSim.drawMap();
	
	// MapTree
	MapTree mapTree(mapSim);
	
	// Rand display
	mapTree.generateRandVertices();
	mapSim.drawMap(mapTree.getVertices());
	
	// Selection
	mapTree.selectVertices();
	mapSim.drawMap(mapTree.getVertices());
	
	// Adding source, target
	Pos src(80,80);
	Pos dest(300,300);	
	mapSim.drawMapSrcDest(src, dest, mapTree.getVertices());

	// Build graph
	mapTree.initGraph(src, dest);
	mapSim.drawMapGraph(mapTree.getVertices(), mapTree.getGraph());
	
	// Dijkstra algorithm
	mapTree.dijkstra();
	mapSim.drawMapGraphPath(mapTree.getVertices(), mapTree.getGraph(), mapTree.getShortestPath());
	
	// Shortest path points :
	std::vector<Pos> sp = mapTree.getShortestPath();
	std::cout << "sp size = " << sp.size() << std::endl;
	for(size_t ind = 0 ; ind < sp.size() ; ++ind)
	{
		std::cout << "sp[" << ind << "] : (" << sp[ind].i << "," << sp[ind].j << ")" << std::endl;	
	}
*/
	
   return 0;
}
