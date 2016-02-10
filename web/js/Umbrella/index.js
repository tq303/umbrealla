import THREE from 'three';

class Umbrella {
    constructor(ledCount) {

        this.ledCount = ledCount;

        // scene and camera
        this.scene    = new THREE.Scene();
        this.camera   = new THREE.PerspectiveCamera( 75, 480 / 320, 1, 10000 );
        this.camera.position.z = 100;

        // geometry and material
        this.geometry = this.createArm();

        this.material = new THREE.LineBasicMaterial({
            color: 0xffffff
        });

        this.line = new THREE.Line(this.geometry, this.material);

        // add geometry to scene
        this.scene.add( this.line );

        // initialize renderer
        this.renderer = new THREE.WebGLRenderer();
        this.renderer.setSize( 480, 320 );

        document.getElementById('umbrella').appendChild( this.renderer.domElement );

        this.animate();
    }
    animate() {
        requestAnimationFrame( () => this.animate() );
        this.renderer.render( this.scene, this.camera );
    }
    createArm() {
        let arm    = new THREE.Geometry(),
            radius = 30;

        for (let i = 0; i <= this.ledCount; i++) {
            let angle = ( (90 / this.ledCount) * i );
            let x = Math.cos(this.radians(angle)) * radius;
            let y = Math.sin(this.radians(angle)) * radius;
            arm.vertices.push(new THREE.Vector3(x, y, 0));
        }

        return arm;
    }
    radians(degrees) {
        return degrees * (Math.PI / 180);
    }
}

export default Umbrella;
