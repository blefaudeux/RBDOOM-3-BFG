#include <idlib/containers/List.h>

#if defined(USE_TET)
#include <libs/tet/include/gazeapi.h>

// --- idGaze definition
class idGaze : public gtl::IGazeListener
{
    public:
        idGaze();
        ~idGaze();

    private:
        // IGazeListener
        void on_gaze_data( gtl::GazeData const & gaze_data );

    public:
        gtl::GazeApi m_api;
        idList< std::pair<float, float> > m_gazePoints;
};
#endif
