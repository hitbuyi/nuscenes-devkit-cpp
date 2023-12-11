import _nuscenes as nuscenes
from pathlib import Path


def test_load():
    nusc = nuscenes.Nuscenes(path="./data", version="v1.0-mini", verbose=True)
    assert nusc is not None
    assert isinstance(nusc, nuscenes.Nuscenes)
    assert isinstance(nusc.path, Path)
    assert nusc.path == Path("./data")
    assert isinstance(nusc.version, str)
    assert nusc.version == "v1.0-mini"
    assert isinstance(nusc.verbose, bool)
    assert nusc.verbose is True
