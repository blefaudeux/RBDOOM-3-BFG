#include "gaze.h"
#if defined(USE_TET)
#include <algorithm>

// --- MyGaze implementation
idGaze::idGaze()
{
    // Connect to the server in push mode on the default TCP port (6555)
    if( m_api.connect( true ) )
    {
        // Enable GazeData notifications
        m_api.add_listener( *this );
        // common->Warning( "Connected to The Eye Tribe server" );
    }
}

idGaze::~idGaze()
{
    m_api.remove_listener( *this );
    m_api.disconnect();
}

void idGaze::on_gaze_data( gtl::GazeData const & gaze_data )
{
    if( gaze_data.state /* & gtl::GazeData::GD_STATE_TRACKING_GAZE */ )
    {
        m_gazePoints.push_back( gaze_data.avg );
    }

    // Restrain the list to the last 10 gaze points (not sure that we actually pick the last 10 here..)
    m_gazePoints.resize( std::min(10, int(m_gazePoints.size())) );
}

#endif
