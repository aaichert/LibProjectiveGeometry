
#include <fstream>
#include <iostream>

#include <LibProjectiveGeometry/ProjectiveGeometry.hxx>
#include <LibProjectiveGeometry/SourceDetectorGeometry.h>

#include <Utils/Projtable.hxx>

void write_example_file() {
  std::ofstream file("example_1_7_15.ompl");
  file << 
"#> spacing=\"-0.154\" detector_size_px=\"2480 1920\"\n"
"[-7792.2 1240 -14.4892 -965964; -14.1303 962.255 7791.92 -817535; 2.11544e-008 1 -0.000289447 -785.32] \n"
"[1230.94 7782.4 -418.668 -978993; 3603.16 -41.6987 6975.36 -762806; 0.937877 -0.00767127 -0.346883 -784.875] \n"
"[7312.47 2928.72 454.41 -979086; -915.096 1504.15 7651.16 -769224; 0.473482 -0.811823 0.341698 -785.35] ";
}


int main(int argc, char ** argv)
{
    // Write example ompl file to disk and load it
	write_example_file();
    // Load input data (expects three matrices)
	std::string input_file = (argc == 2 ? argv[1]: "example_1_7_15.ompl");
	auto Ps=ProjTable::loadProjectionsOneMatrixPerLine(input_file);
    Geometry::ProjectionMatrix P0 = Ps[0];
    Geometry::ProjectionMatrix P1 = Ps[1];
    Geometry::ProjectionMatrix P2 = Ps[2];
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "P0 " << P0 << std::endl;
    std::cout << "P1 " << P1 << std::endl;
    std::cout << "--------------------------------------------------------------------\n";
	std::cout << "Geometry::pseudoInverse(P0)" << std::endl;
    std::cout <<  Geometry::pseudoInverse(P0)  << std::endl;
    std::cout << "--------------------------------------------------------------------\n";
    Eigen::Matrix3d K;
    Eigen::Matrix3d R;
    Eigen::Vector3d t;
    std::cout << "Geometry::projectionMatrixDecomposition(P0, K, R, t, true)" << std::endl;
	std::cout <<  Geometry::projectionMatrixDecomposition(P0, K, R, t, true) << std::endl;
    std::cout << "--\n";
    std::cout << "K " << K << std::endl;
    std::cout << "R " << R << std::endl;
    std::cout << "t " << t << std::endl;
    std::cout << "--------------------------------------------------------------------\n";
	std::cout << "Geometry::makeProjectionMatrix(K,R,t)" << std::endl;
	std::cout <<  Geometry::makeProjectionMatrix(K,R,t) << std::endl;
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "Geometry::getCameraIntrinsics(P0)" << std::endl;
	std::cout <<  Geometry::getCameraIntrinsics(P0) << std::endl << std::endl;
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "Geometry::getCameraCenter(P0)" << std::endl;
    std::cout <<  Geometry::getCameraCenter(P0) << std::endl;
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "Geometry::getCameraPrincipalPoint(P0)" << std::endl;
    std::cout <<  Geometry::getCameraPrincipalPoint(P0) << std::endl;
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "Geometry::getCameraDirection(P0)" << std::endl;
    std::cout <<  Geometry::getCameraDirection(P0) << std::endl;
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "Geometry::getCameraAxisDirections(P0)" << std::endl;
    auto UV = Geometry::getCameraAxisDirections(P0);
    std::cout << "--\n";
    std::cout <<  "U " << UV.first << std::endl;
    std::cout <<  "V " << UV.second << std::endl;
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "Geometry::getCameraFocalLengthPx(P0)" << std::endl;
    auto axy = Geometry::getCameraFocalLengthPx(P0);
    std::cout << "--\n";
    std::cout <<  "ax " << axy.first << std::endl;
    std::cout <<  "ay " << axy.second << std::endl;
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "Geometry::getCameraImagePlane(P0,-0.154)" << std::endl;
    std::cout <<  Geometry::getCameraImagePlane(P0,-0.154) << std::endl;
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "Geometry::computeFundamentalMatrix(P0, P1)" << std::endl;
    std::cout << Geometry::computeFundamentalMatrix(P0, P1) << std::endl;
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "Geometry::computeFundamentalMatrix(P0, P2)" << std::endl;
    std::cout << Geometry::computeFundamentalMatrix(P0, P2) << std::endl;

    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "--------------------------------------------------------------------\n";
    std::cout <<  "Geometry::SourceDetectorGeometry sdg(P0,-0.154)" << std::endl;
    Geometry::SourceDetectorGeometry sdg(P0,-0.154);
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "--- Vectors defining a projection matrix\n";
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "Center of projection (i.e. source position)\n" << sdg.C << std::endl;
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "Detector origin in three-space\n" << sdg.O << std::endl;
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "Inifinte point in u-direction (scaled to pixel size)\n" << sdg.U << std::endl;
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "Inifinte point in v-direction (scaled to pixel size)\n" << sdg.V << std::endl;
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "--- Additional related objects for utility\n";
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "Principal Point in three-space\n" << sdg.principal_point_3d << std::endl;
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "Principal plane\n" << sdg.principal_plane << std::endl;
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "Image plane\n" << sdg.image_plane << std::endl;
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "Projection to image plane\n" << sdg.central_projection << std::endl;
    

    return 0;
}
