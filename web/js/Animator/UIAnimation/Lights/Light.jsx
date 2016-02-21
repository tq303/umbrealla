import React from 'react';

class Light extends React.Component {

    constructor() {

        super();

        this.iColour = '#777';

        this.state = {
            active: false,
            activeClass: '',
            activeStyle: {
                color: this.iColour
            },
            colour: '#337ab7'
        }
    }

    toggleActive() {
        this.setState(( state )=> {
            return {
                active: !state.active,
                activeClass: ( state.active ) ? '' : 'active',
                activeStyle: {
                    color: ( state.active ) ? this.iColour : state.colour
                }
            }
        });
    }

    setColour( colour ) {
        this.setState({
            activeStyle: {
                color: colour
            },
            colour: colour
        });
    }

    render() {
        return (
            <a className={ this.state.activeClass } style={ this.state.activeStyle } onClick={ this.toggleActive.bind(this) }></a>
        )
    }
}

export default Light
