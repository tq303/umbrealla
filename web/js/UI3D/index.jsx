import React from 'react';

import CameraPosition from './CameraPosition';

require('../../styles/ui-3d.scss');

class UI3D extends React.Component {
    render() {
        return (
            <CameraPosition canvas={ this.props.canvas } />
        )
    }
}

UI3D.propTypes = {
    canvas: React.PropTypes.object.isRequired
};

export default UI3D;
