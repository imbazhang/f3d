#ifndef vtkF3DPdalImporter_h
#define vtkF3DPdalImporter_h

#include "vtkF3DImporter.h"
#include <memory>
#include <vtkVersion.h>

class vtkF3DPdalImporter : public vtkF3DImporter
{
public:
  static vtkF3DPdalImporter* New();
  vtkTypeMacro(vtkF3DPdalImporter, vtkF3DImporter);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  vtkSetMacro(FileName, std::string);
  vtkGetMacro(FileName, std::string);

  void ImportPointCloudData(vtkRenderer* renderer);

  std::string GetOutputsDescription() override;

protected:
  vtkF3DPdalImporter();
  ~vtkF3DPdalImporter() override;

  int ImportBegin() override;
  void ImportActors(vtkRenderer*) override;
  void ImportCameras(vtkRenderer*) override;
  void ImportLights(vtkRenderer*) override;

private:
  std::string FileName;

  vtkF3DPdalImporter(const vtkF3DPdalImporter&) = delete;
  void operator=(const vtkF3DPdalImporter&) = delete;

  class vtkInternals;
  std::unique_ptr<vtkInternals> Internals;
};

#endif