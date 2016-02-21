import React from 'react';

import Cycle  from './Cycle';
import Lights from './Lights';

class UIAnimation extends React.Component {
    render() {
        return (
            <div>
                <Cycle/>
                <Lights/>
            </div>
        )
    }
}

export default UIAnimation;
