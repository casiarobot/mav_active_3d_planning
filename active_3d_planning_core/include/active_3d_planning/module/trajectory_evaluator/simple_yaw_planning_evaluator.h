#ifndef ACTIVE_3D_PLANNING_CORE_TRAJECTORY_EVALUATOR_SIMPLE_YAW_PLANNING_EVALUATOR_H
#define ACTIVE_3D_PLANNING_CORE_TRAJECTORY_EVALUATOR_SIMPLE_YAW_PLANNING_EVALUATOR_H

#include "active_3d_planning/module/trajectory_evaluator/yaw_planning_evaluator.h"

namespace active_3d_planning {
namespace evaluator_updater {
class YawPlanningUpdater;
}
namespace trajectory_evaluator {

// Simple evaluator. Samples yaws uniformly and assigns the same yaw to all
// trajectory points.
class SimpleYawPlanningEvaluator : public YawPlanningEvaluator {
public:
  SimpleYawPlanningEvaluator(PlannerI &planner);
  // Override virtual functions
  void visualizeTrajectoryValue(visualization_msgs::MarkerArray *msg,
                                const TrajectorySegment &trajectory) override;

  void setupFromParamMap(Module::ParamMap *param_map) override;

protected:
  friend class evaluator_updater::YawPlanningUpdater;

  static ModuleFactoryRegistry::Registration<SimpleYawPlanningEvaluator>
      registration;

  // params
  bool p_visualize_followup_; // true: also visualize the gain of the best
                              // orientation

  // methods
  double sampleYaw(double original_yaw, int sample);
  void setTrajectoryYaw(TrajectorySegment *segment, double start_yaw,
                        double target_yaw);
};

} // namespace trajectory_evaluator
} // namespace active_3d_planning
#endif // ACTIVE_3D_PLANNING_CORE_TRAJECTORY_EVALUATOR_SIMPLE_YAW_PLANNING_EVALUATOR_H