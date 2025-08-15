from setuptools import find_packages, setup

package_name = 'my_robot_python'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='vincent-pc',
    maintainer_email='vncnt.mh@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "my_robot_j0_py = my_robot_python.my_robot_joint0:main",
            "my_robot_j1_py = my_robot_python.my_robot_joint1:main",
        ],
    },
)
