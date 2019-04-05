/* Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
   file Copyright.txt or https://cmake.org/licensing for details.  */
#ifndef cmQtAutoGeneratorRcc_h
#define cmQtAutoGeneratorRcc_h

#include "cmConfigure.h" // IWYU pragma: keep

#include "cmFileLock.h"
#include "cmFileTime.h"
#include "cmQtAutoGenerator.h"

#include <string>
#include <vector>

class cmMakefile;

// @brief AUTORCC generator
class cmQtAutoGeneratorRcc : public cmQtAutoGenerator
{
public:
  cmQtAutoGeneratorRcc();
  ~cmQtAutoGeneratorRcc() override;

  cmQtAutoGeneratorRcc(cmQtAutoGeneratorRcc const&) = delete;
  cmQtAutoGeneratorRcc& operator=(cmQtAutoGeneratorRcc const&) = delete;

private:
  // -- Abstract processing interface
  bool Init(cmMakefile* makefile) override;
  bool Process() override;
  // -- Settings file
  bool SettingsFileRead();
  bool SettingsFileWrite();
  // -- Tests
  bool TestQrcRccFiles(bool& generate);
  bool TestResources(bool& generate);
  bool TestInfoFile();
  // -- Generation
  bool GenerateParentDir();
  bool GenerateRcc();
  bool GenerateWrapper();

  // -- Utility
  bool IsMultiConfig() const { return MultiConfig_; }
  std::string MultiConfigOutput() const;

private:
  // -- Config settings
  bool MultiConfig_ = false;
  // -- Directories
  std::string AutogenBuildDir_;
  std::string IncludeDir_;
  // -- Qt environment
  std::string RccExecutable_;
  std::vector<std::string> RccListOptions_;
  // -- Job
  std::string LockFile_;
  cmFileLock LockFileLock_;
  std::string QrcFile_;
  std::string QrcFileName_;
  std::string QrcFileDir_;
  cmFileTime QrcFileTime_;
  std::string RccPathChecksum_;
  std::string RccFileName_;
  std::string RccFileOutput_;
  std::string RccFilePublic_;
  cmFileTime RccFileTime_;
  std::vector<std::string> Options_;
  std::vector<std::string> Inputs_;
  // -- Settings file
  std::string SettingsFile_;
  std::string SettingsString_;
  bool SettingsChanged_ = false;
  bool BuildFileChanged_ = false;
};

#endif
