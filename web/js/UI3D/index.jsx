import React from 'react';

import CameraPosition from './CameraPosition';

require('../../styles/ui-3d.scss');

class UI3D extends React.Component {
    render() {
        return (
            <CameraPosition umbrella={ this.props.umbrella } />
        )
    }
}

UI3D.propTypes = {
    umbrella: React.PropTypes.object.isRequired
};

export default UI3D;
