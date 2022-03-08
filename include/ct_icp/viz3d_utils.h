#ifndef CT_ICP_VIZ3D_UTILS_H
#define CT_ICP_VIZ3D_UTILS_H

#ifdef CT_ICP_WITH_VIZ

#include <SlamCore-viz3d/viz3d_windows.h>
#include <SlamCore-viz3d/viz3d_utils.h>

#include "ct_icp/odometry.h"

namespace ct_icp {

    /*!
     * A callback which displays frames
     */
    class ShowAggregatedFramesCallback : public Odometry::OdometryCallback {
    public:

        // Adds the current_frame to the slam::MultiPolyDataWindow this callback points to
        bool Run(const Odometry &,
                 const std::vector<slam::WPoint3D> &current_frame,
                 const std::vector<slam::WPoint3D> * = nullptr,
                 const Odometry::RegistrationSummary * = nullptr) override;

        explicit ShowAggregatedFramesCallback(slam::MultiPolyDataWindow *window) : window_(window) {}

        // The maximum number of frames to sequentially add to the window
        REF_GETTER(MaxNumFrames, max_num_frames_);

        // The name of the group of poly data in the slam::MultiPolyDataWindow
        REF_GETTER(GroupName, group_name_);

    private:
        std::string group_name_ = "AGGREGATED_POINTS";
        int max_num_frames_ = 100;
        slam::MultiPolyDataWindow *window_ = nullptr;
        std::set<slam::frame_id_t> frame_ids_;
    };

}

#endif

#endif //CT_ICP_VIZ3D_UTILS_H
