#ifndef OPENVSLAM_FEATURE_ORB_EXTRACTOR_NODE_H
#define OPENVSLAM_FEATURE_ORB_EXTRACTOR_NODE_H

#include <list>

#include <opencv2/core/types.hpp>

namespace openvslam {
namespace feature {

class orb_extractor_node {
public:
    //! Constructor
    orb_extractor_node() = default;

    //! Divide node to four child nodes  一个父节点对应展开4个子叶节点 将一个矩形等分为4等份，每份为被一个子叶节点掌握
    std::array<orb_extractor_node, 4> divide_node();

    //! Keypoints which distributed into this node 以该结点为父节点的特征点
    std::vector<cv::KeyPoint> keypts_;

    //! Begin and end of the allocated area on the image  该节点掌控的区域，矩形的对角点
    cv::Point2i pt_begin_, pt_end_;

    //! A iterator pointing to self, used for removal on list   nodes是链表结构，为了方便给指定的node中添加特征点，使用vector保存每个node的指针
    std::list<orb_extractor_node>::iterator iter_;

    //! A flag designating if this node is a leaf node
    bool is_leaf_node_ = false;
};

} // namespace feature
} // namespace openvslam

#endif // OPENVSLAM_FEATURE_ORB_EXTRACTOR_NODE_H
