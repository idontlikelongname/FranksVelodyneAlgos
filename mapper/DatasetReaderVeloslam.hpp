#ifndef DATASETREADERVELOSLAM_H
#define DATASETREADERVELOSLAM_H

#include <CsvReader.hpp>
#include <vector>

#include "DatasetReader.hpp"

class DataSetReaderVeloSlam : public DataSetReader
{
public:
  DataSetReaderVeloSlam(std::string baseDir);
  virtual ~DataSetReaderVeloSlam();

  virtual std::string getBaseDirectory() const;
  virtual std::string getPngConfigFilename() const;
  virtual int getFrameCount() const;
  virtual ImuData getImuData(int index) const;
  virtual PngFile getDistancePng(int index) const;
  virtual PngFile getIntensityPng(int index) const;

private:
  std::string baseDirectory;
  int frameCount;

  CsvReader *insReader;
  static const size_t insFirstLineNb = 8; // the 8th line (i.e. at index 7) contains the first data row
  std::vector<std::string> distancePngFiles;
  std::vector<std::string> intensityPngFiles;

  void initImuReader();
  void scanForImages();
};

#endif // DATASETREADERVELOSLAM_H
