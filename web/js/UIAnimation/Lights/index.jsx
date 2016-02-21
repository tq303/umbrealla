import React from 'react';

import Light from './Light';

class Lights extends React.Component {

    constructor( params ) {
        super( params );

        // assign <Light/> to this.lights array
        this.lights = [];

        for (let i = 0; i < this.props.stripCount; i++ ) {
            this.lights[i] = <Light/>;
        }

    }

    render() {
        return (
            <div id="ui-lights">

                <div className="controls">
                    
                </div>

                <p>{ this.lights[0] }</p>
                <p>{ this.lights[7] }{ this.lights[1] }</p>
                <p>{ this.lights[6] }{ this.lights[2] }</p>
                <p>{ this.lights[5] }{ this.lights[3] }</p>
                <p>{ this.lights[4] }</p>

            </div>
        )
    }
}

Lights.propTypes = {
    stripCount: React.PropTypes.number.isRequired
};

export default Lights;
