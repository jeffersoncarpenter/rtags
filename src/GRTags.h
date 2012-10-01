#ifndef GRTags_h
#define GRTags_h

#include "Project.h"
#include "FileSystemWatcher.h"

class GRParseJob;
class GRTags
{
public:
    GRTags();
    void init(const shared_ptr<Project> &project);
    void onFileAdded(const Path &path);
    void onFileRemoved(const Path &path);
    void onRecurseJobFinished(const Set<Path> &files);
    void recurse();
    void add(const Path &source);
    void onParseJobFinished(const shared_ptr<GRParseJob> &job, const GRMap &data);
    void dirty(uint32_t fileId, GRMap &map);
    bool isIndexed(uint32_t fileId) const;
private:
    weak_ptr<Project> mProject;
    FileSystemWatcher mWatcher;
    int mActive, mCount;
};

#endif
