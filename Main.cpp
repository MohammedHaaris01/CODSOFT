#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void displayImage(Mat& image) {
    namedWindow("Image", WINDOW_NORMAL);
    imshow("Image", image);
    waitKey(0);
    destroyWindow("Image");
}

void applyGrayscale(Mat& image) {
    cvtColor(image, image, COLOR_BGR2GRAY);
}

void applyBlur(Mat& image) {
    GaussianBlur(image, image, Size(5, 5), 0);
}

void applySharpen(Mat& image) {
    Mat kernel = (Mat_<float>(3, 3) <<
        -1, -1, -1,
        -1, 9, -1,
        -1, -1, -1);
    filter2D(image, image, image.depth(), kernel);
}

void adjustColors(Mat& image, float brightness, float contrast) {
    image.convertTo(image, -1, contrast, brightness);
}

void cropImage(Mat& image, Rect cropRegion) {
    image = image(cropRegion);
}

void resizeImage(Mat& image, Size newSize) {
    resize(image, image, newSize);
}

int main() {
    Mat image = imread("image.png");

    if (image.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    while (true) {
        int choice;
        cout << "Choose an operation:" << endl;
        cout << "1. Display Image" << endl;
        cout << "2. Grayscale" << endl;
        cout << "3. Blur" << endl;
        cout << "4. Sharpen" << endl;
        cout << "5. Adjust Colors" << endl;
        cout << "6. Crop Image" << endl;
        cout << "7. Resize Image" << endl;
        cout << "8. Save Image" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displayImage(image);
            break;
        case 2:
            applyGrayscale(image);
            break;
        case 3:
            applyBlur(image);
            break;
        case 4:
            applySharpen(image);
            break;
        case 5: {
            float brightness, contrast;
            cout << "Enter brightness (-100 to 100): ";
            cin >> brightness;
            cout << "Enter contrast (0 to 100): ";
            cin >> contrast;
            adjustColors(image, brightness, contrast / 100.0);
            break;
        }
        case 6: {
            int x, y, width, height;
            cout << "Enter x-coordinate of top-left corner: ";
            cin >> x;
            cout << "Enter y-coordinate of top-left corner: ";
            cin >> y;
            cout << "Enter width: ";
            cin >> width;
            cout << "Enter height: ";
            cin >> height;
            cropImage(image, Rect(x, y, width, height));
            break;
        }
        case 7: {
            int width, height;
            cout << "Enter new width: ";
            cin >> width;
            cout << "Enter new height: ";
            cin >> height;
            resizeImage(image, Size(width, height));
            break;
        }
        case 8:
            imwrite("processed_image.jpg", image);
            cout << "Image saved successfully" << endl;
            break;
        case 9:
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
