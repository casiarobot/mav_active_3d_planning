#ifndef ACTIVE_3D_PLANNING_SEGMENT_SELECTOR_DEFAULT_SEGMENT_SELECTORS_H
#define ACTIVE_3D_PLANNING_SEGMENT_SELECTOR_DEFAULT_SEGMENT_SELECTORS_H

#include "active_3d_planning_core/module/trajectory_generator.h"

namespace active_3d_planning {
    namespace segment_selector {

        // Select segment with highest value
        class GreedySelector : public SegmentSelector {
        public:
            explicit GreedySelector(PlannerI &planner);

            // override virtual functions
            bool selectSegment(TrajectorySegment **result,
                               TrajectorySegment *root) override;

            void setupFromParamMap(Module::ParamMap *param_map) override;

        protected:
            static ModuleFactoryRegistry::Registration<GreedySelector> registration;

            // variables
            bool leaves_only_;
        };

    } // namespace segment_selector
} // namespace active_3d_planning
#endif // ACTIVE_3D_PLANNING_SEGMENT_SELECTOR_DEFAULT_SEGMENT_SELECTORS_H
