#include "flightlib/bridges/unity_bridge.hpp"
#include "flightlib/common/logger.hpp"
#include "flightlib/objects/static_gate.hpp"

#include <gtest/gtest.h>

using namespace flightlib;

TEST(UnityBridge, Constructor) {
  Logger logger{"Test Unity Bridge"};
  UnityBridge unity_bridge;
  // bool unity_ready = false;

  // // need to add a quad to connect to Flightmare
  // QuadrotorDynamics dyn = QuadrotorDynamics(1.0, 0.2);
  // std::shared_ptr<Quadrotor> quad = std::make_shared<Quadrotor>(dyn);
  // unity_bridge.addQuadrotor(quad);

  // unity_ready = unity_bridge.connectUnity(UnityScene::GARAGE);

  // if (unity_ready) logger.info("Unity Rendering is connected");
  // EXPECT_TRUE(unity_ready);
  // //timeout flightmare
  // usleep(5 * 1e6);
}

TEST(UnityBridge, PointCloud) {
  Logger logger{"Test PointCloud"};
  UnityBridge unity_bridge;

  // // need to add a quad to connect to Flightmare
  // QuadrotorDynamics dyn = QuadrotorDynamics(1.0, 0.2);
  // std::shared_ptr<Quadrotor> quad = std::make_shared<Quadrotor>(dyn);
  // unity_bridge.addQuadrotor(quad);

  // EXPECT_TRUE(unity_bridge.connectUnity(UnityScene::GARAGE));
  // PointCloudMessage_t pointcloud_msg;
  // pointcloud_msg.path = "/tmp/";
  // pointcloud_msg.file_name = "unity-bridge" + std::to_string(::rand());
  // EXPECT_TRUE(unity_bridge.getPointCloud(pointcloud_msg, 30.0));
  // std::experimental::filesystem::remove(pointcloud_msg.path +
  //                                       pointcloud_msg.file_name + ".ply");
  // // timeout flightmare
  // usleep(5 * 1e6);
}

TEST(UnityBridge, HandleOutputRGB) {
  Logger logger{"Test HandleOutputRGB"};
  UnityBridge unity_bridge;
  // QuadrotorDynamics dyn = QuadrotorDynamics(1.0, 0.2);
  // std::shared_ptr<Quadrotor> quad = std::make_shared<Quadrotor>(dyn);
  // std::shared_ptr<RGBCamera> rgb = std::make_shared<RGBCamera>();
  // quad->addRGBCamera(rgb);
  // unity_bridge.addQuadrotor(quad);

  // EXPECT_TRUE(unity_bridge.connectUnity(UnityScene::GARAGE));

  // FrameID frame_id = 1;
  // unity_bridge.getRender(frame_id);
  // bool handle_output = unity_bridge.handleOutput();

  // EXPECT_TRUE(handle_output);

  // cv::Mat test_img;

  // EXPECT_TRUE(rgb->getRGBImage(test_img));
  // EXPECT_FALSE(rgb->getDepthMap(test_img));
  // EXPECT_FALSE(rgb->getSegmentation(test_img));
  // EXPECT_FALSE(rgb->getOpticalFlow(test_img));

  // // timeout flightmare
  // usleep(5 * 1e6);
}

TEST(UnityBridge, HandleOutputDepth) {
  Logger logger{"Test HandleOutputDepth"};
  UnityBridge unity_bridge;
  // QuadrotorDynamics dyn = QuadrotorDynamics(1.0, 0.2);
  // std::shared_ptr<Quadrotor> quad = std::make_shared<Quadrotor>(dyn);
  // std::shared_ptr<RGBCamera> rgb = std::make_shared<RGBCamera>();
  // rgb->setPostPrecesscing(std::vector<bool>{true, false, false});
  // quad->addRGBCamera(rgb);
  // unity_bridge.addQuadrotor(quad);

  // EXPECT_TRUE(unity_bridge.connectUnity(UnityScene::GARAGE));

  // FrameID frame_id = 1;
  // unity_bridge.getRender(frame_id);
  // bool handle_output = unity_bridge.handleOutput();

  // EXPECT_TRUE(handle_output);

  // cv::Mat test_img;

  // EXPECT_TRUE(rgb->getRGBImage(test_img));
  // EXPECT_TRUE(rgb->getDepthMap(test_img));
  // EXPECT_FALSE(rgb->getSegmentation(test_img));
  // EXPECT_FALSE(rgb->getOpticalFlow(test_img));

  // // timeout flightmare
  // usleep(5 * 1e6);
}

TEST(UnityBridge, HandleOutputSegmentation) {
  Logger logger{"Test HandleOutputSegmentation"};
  UnityBridge unity_bridge;
  // QuadrotorDynamics dyn = QuadrotorDynamics(1.0, 0.2);
  // std::shared_ptr<Quadrotor> quad = std::make_shared<Quadrotor>(dyn);
  // std::shared_ptr<RGBCamera> rgb = std::make_shared<RGBCamera>();
  // rgb->setPostPrecesscing(std::vector<bool>{false, true, false});
  // quad->addRGBCamera(rgb);
  // unity_bridge.addQuadrotor(quad);

  // EXPECT_TRUE(unity_bridge.connectUnity(UnityScene::GARAGE));

  // FrameID frame_id = 1;
  // unity_bridge.getRender(frame_id);
  // bool handle_output = unity_bridge.handleOutput();

  // EXPECT_TRUE(handle_output);

  // cv::Mat test_img;

  // EXPECT_TRUE(rgb->getRGBImage(test_img));
  // EXPECT_FALSE(rgb->getDepthMap(test_img));
  // EXPECT_TRUE(rgb->getSegmentation(test_img));
  // EXPECT_FALSE(rgb->getOpticalFlow(test_img));

  // // timeout flightmare
  // usleep(5 * 1e6);
}

TEST(UnityBridge, HandleOutputOpticalFlow) {
  Logger logger{"Test HandleOutputOpticalFlow"};
  UnityBridge unity_bridge;
  QuadrotorDynamics dyn = QuadrotorDynamics(1.0, 0.2);
  std::shared_ptr<Quadrotor> quad = std::make_shared<Quadrotor>(dyn);
  std::shared_ptr<RGBCamera> rgb = std::make_shared<RGBCamera>();
  rgb->setPostPrecesscing(std::vector<bool>{false, false, true});
  quad->addRGBCamera(rgb);
  unity_bridge.addQuadrotor(quad);

  EXPECT_TRUE(unity_bridge.connectUnity(UnityScene::GARAGE));

  FrameID frame_id = 1;
  unity_bridge.getRender(frame_id);
  bool handle_output = unity_bridge.handleOutput();

  EXPECT_TRUE(handle_output);

  cv::Mat test_img;

  EXPECT_TRUE(rgb->getRGBImage(test_img));
  EXPECT_FALSE(rgb->getDepthMap(test_img));
  EXPECT_FALSE(rgb->getSegmentation(test_img));
  EXPECT_TRUE(rgb->getOpticalFlow(test_img));
  cv::imwrite("/tmp/optical.png", test_img);

  // timeout flightmare
  usleep(5 * 1e6);
}

TEST(UnityBridge, SpawnStaticGate) {
  Logger logger{"Test SpawnStaticGate"};
  UnityBridge unity_bridge;
  QuadrotorDynamics dyn = QuadrotorDynamics(1.0, 0.2);
  std::shared_ptr<Quadrotor> quad = std::make_shared<Quadrotor>(dyn);
  std::shared_ptr<RGBCamera> rgb = std::make_shared<RGBCamera>();
  std::string object_id = "unity_gate";
  std::string prefab_id = "rpg_gate";
  std::shared_ptr<StaticGate> obj =
    std::make_shared<StaticGate>(object_id, prefab_id);
  rgb->setPostPrecesscing(std::vector<bool>{false, false, true});
  quad->addRGBCamera(rgb);
  unity_bridge.addQuadrotor(quad);
  unity_bridge.addStaticObject(obj);

  EXPECT_TRUE(unity_bridge.connectUnity(UnityScene::GARAGE));
}