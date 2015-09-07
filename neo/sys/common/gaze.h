#if defined(USE_TET)
#include <libs/tet/include/gazeapi.h>
#include <vector>

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
        std::vector< gtl::Point2D > m_gazePoints;
};
#endif
