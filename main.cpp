#include <iostream>

#include "mavlink_control.h"
#include "camera_recorder.h"
#include "configParam.h"
#include "log.h"
#include "imu_recorder.h"

using namespace std;

int main(int argc, char **argv);

int main(int argc, char **argv) {
    bool bCamera = false;
    bool bIMU = true;
    bool bSLAM = false;

    try {
        ConfigParam configParam(argc, argv);
        Log log("record_data");

        cout << "Starting main in " << configParam.mode << " mode " << endl;
        IMU_Recorder imu_recorder(true);
        Mavlink_Control mavlinkControl(&configParam, &imu_recorder);
        Camera_Recorder cameraRecorder(0);
        if(bIMU){
            mavlinkControl.start();
        }
        if(bCamera) cameraRecorder.start();
        mavlinkControl.cmd();
        if(bCamera) cameraRecorder.stop();
        if(bIMU)mavlinkControl.stop();

        return 0;
    }
    catch (int error) {
        fprintf(stderr, "threw exception %i \n", error);
        return error;
    }
}
