#ifndef HOG_GETTER_H
#define HOG_GETTER_H

#include "platform.h"   


class HogGetter {
public:

    HogGetter() {
        cv::HOGDescriptor d(Size(64,128), Size(16,16), Size(8,8), Size(8,8), 9);        
        this->set_scriptor(d);
    }
    ~HogGetter() {}
private:// 数据成员
    cv::HOGDescriptor hog_scriptor_;    // hog检测器
    cv::Size window_size_;              // 检测窗口的大小，即待检测图片的大小
    cv::Size cell_size_;                // cell
    cv::Size block_size_;               // block
    cv::Size block_stride_;             // block 滑动的步长，注意需要两个方向
    int hist_bins_;                     // 直方图的 bin 个数

    cv::Mat sample_features_;                   // 样本个 row, 每一 row 为该样本的 HOG feature lable 
    std::vector<std::string> raw_images_paths_; // 所有样本 paths
    std::vector<cv::Mat> raw_images_;           // 所有样本 vector

    int feature_vector_dimesion_;               // 特征向量的维度
    int sample_nums_;                           // 训练样本的数量
public:// 设置数据成员的接口
    void set_scriptor(const cv::HOGDescriptor&);// 直接给一个检测器 
    void set_window_size(const cv::Size&);           
    void set_cell_size(const cv::Size&);
    void set_block_size(const cv::Size&);
    void set_block_stride(const cv::Size&);
    void set_nbins(const int&);
public:// 函数接口
    void ImagePathReader_(const string& folder_path, const string& postfix);    // read images' paths
    cv::Mat RandomCutter_(cv::Mat);                     // 随机裁剪
    cv::Mat HogComputter_();                            // 计算 raw_images_ HOG feature，存在 samples_features_
};

#endif