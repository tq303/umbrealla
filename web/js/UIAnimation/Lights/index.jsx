import React from 'react';

import Light from './Light';

class Lights extends React.Component {
    render() {
        return (
            <div id="ui-lights">
                <p><Light/></p>
                <p><Light/><Light/></p>
                <p><Light/><Light/></p>
                <p><Light/><Light/></p>
                <p><Light/></p>
            </div>
        )
    }
}

export default Lights;
